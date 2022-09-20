#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200300;
const int mod = 998244353;

using namespace std;

int n, k;
int a[N];
int c[N];

bool can(int M)
{
        int rem = k;
        for(int i = 0; i < N; i++){
                c[i] = 0;
        }
        rem -= 1;
        c[0] = 1;
        c[1] = -1;
        for(int i = 1, j = -1, cur = 0; i <= n && j < M - 1 && rem > 0; i++){
                if(cur == 0){
                        j += 1;
                        c[j] += c[j - 1];
                        while(j < N && !c[j]){
                                j += 1;
                                if(j > 0){
                                        c[j] += c[j - 1];
                                }
                        }
                        cur = c[j];
                        if(j == N){
                                break;
                        }
                }

                rem += 1;
                cur -= 1;
                int X = (a[i] - 1) / 2;
                int Y = (a[i] - 1) - X;
                X = min(X, M - j - 1);
                Y = min(Y, M - j - 1);

                //cout << rem << " " << X << " " << Y << " " << j << "\n";

                rem -= X + Y;
                c[j + 2] += 2;

                c[min(j + 2 + X, N - 1)] -= 1;
                c[min(j + 2 + Y, N - 1)] -= 1;
        }

        return rem <= 0;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);

        //cout << can(3) << "\n";
        //return 0;

        int l = 0, r = 1e9;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        if(l == 1e9){
                l = -1;
        }
        cout << l << "\n";
}