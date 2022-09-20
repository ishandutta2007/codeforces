#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s;
        int x, y;
        cin >> s >> x >> y;
        int n = s.size();
        long long inf = 1e18;
        long long res = inf;
        for(int it = 0; it < 2; it++){
                vector < long long > L(n + 1, 0), R(n + 1, 0);
                vector < vector < int > > C(n + 1, vector < int > (3, 0));
                for(int i = 0, c1 = 0, c0 = 0; i < n; i++){
                        if(s[i] == '1'){
                                L[i] += 1ll * c0 * x;
                                c1 += 1;
                        } else{
                                L[i] += 1ll * c1 * y;
                                c0 += 1;
                        }
                        L[i + 1] = L[i];

                        if(s[i] == '0'){
                                C[i][0] += 1;
                        } else if(s[i] == '1'){
                                C[i][1] += 1;
                        } else{
                                C[i][2] += 1;
                        }
                        C[i + 1] = C[i];
                }
                for(int i = n - 1, c1 = 0, c0 = 0; i >= 0; i--){
                        R[i] = R[i + 1];
                        if(s[i] == '0'){
                                R[i] += 1ll * c1 * x;
                                c0 += 1;
                        } else{
                                R[i] += 1ll * c0 * y;
                                c1 += 1;
                        }
                }
                res = min(res, min(L[n], R[0]));
                for(int i = 0; i + 1 < n; i++){
                        long long cur = L[i] + R[i + 1];
                        int c0 = C[i][0] + C[i][2];
                        int c1 = C[n][1] - C[i][1] + C[n][2] - C[i][2];
                        cur += 1ll * c0 * c1 * x;

                        c1 = C[i][1];
                        c0 = C[n][0] - C[i][0];
                        cur += 1ll * c1 * c0 * y;

                        res = min(res, cur);
                }
                reverse(s.begin(), s.end());
                swap(x, y);
        }
        cout << res << "\n";
}