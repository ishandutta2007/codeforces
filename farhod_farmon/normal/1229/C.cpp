#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int B[N];

vector < int > A[N];

long long res;

void upd(int x, int g)
{
        res += 1ll * A[x].size() * B[x] * g;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);


        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;

                if(x > y){
                        A[y].push_back(x);
                        B[x] += 1;
                } else{
                        A[x].push_back(y);
                        B[y] += 1;
                }
        }

        for(int i = 1; i <= n; i++){
                upd(i, 1);
        }

        cout << res << "\n";

        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int x;
                cin >> x;

                upd(x, -1);
                for(int y: A[x]){
                        upd(y, -1);
                        B[y] -= 1;
                        A[y].push_back(x);
                        upd(y, 1);

                }
                B[x] += A[x].size();
                A[x].clear();
                upd(x, 1);

                cout << res << "\n";
        }
}