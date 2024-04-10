#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;
const long long mod = 998244353;

using namespace std;

int n;
string s;
string t;
int d[N][4];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        for(int i = 0; i < N; i++){
                d[i][0] = -1e9;
                d[i][1] = -1e9;
                d[i][2] = -1e9;
                d[i][3] = -1e9;
        }
        cin >> s >> t;
        n = s.size();
        if(s[0] == '0' && t[0] == '0'){
                d[0][0] = 0;
        } else if(s[0] == '0'){
                d[0][1] = 0;
        } else if(t[0] == '0'){
                d[0][2] = 0;
        } else{
                d[0][3] = 0;
        }
        for(int i = 1; i < n; i++){
                int best = -1e9;
                for(int j = 0; j < 4; j++){
                        best = max(best, d[i - 1][j]);
                }
                //hichi namemonem ijada
                if(s[i] == '0' && t[i] == '0'){
                        d[i][0] = best;
                } else if(s[i] == '0'){
                        d[i][1] = best;
                } else if(t[i] == '0'){
                        d[i][2] = best;
                } else{
                        d[i][3] = best;
                }
                //ijada memonem ak
                // yakm namudw
                if(s[i] == '0'){
                        if(t[i] == '0'){
                                d[i][2] = max(d[i][2], d[i - 1][0] + 1);
                        } else{
                                d[i][3] = max(d[i][3], d[i - 1][0] + 1);
                        }
                }
                // duyum namudw
                if(s[i] == '0' && t[i] == '0'){
                        d[i][3] = max(d[i][3], d[i - 1][2] + 1);
                }
                // seyum namudw
                if(s[i] == '0' && t[i] == '0'){
                        d[i][3] = max(d[i][3], d[i - 1][1] + 1);
                }
                // chormw
                if(t[i] == '0'){
                        if(s[i] == '0'){
                                d[i][1] = max(d[i][1], d[i - 1][0] + 1);
                        } else{
                                d[i][3] = max(d[i][3], d[i - 1][0] + 1);
                        }
                }
        }
        int res = -1e9;
        for(int i = 0; i < 4; i++){
                res = max(res, d[n - 1][i]);
        }
        cout << res << "\n";
}