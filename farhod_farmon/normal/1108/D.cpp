#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int d[N][3];
int p[N][3];
string s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        vector < char > v;
        v = {'B', 'R', 'G'};

        cin >> n >> s;
        s = "#" + s;
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < 3; j++){
                        d[i][j] = 1e9;
                }
                for(int j = 0; j < 3; j++){
                        for(int h = 0; h < 3; h++){
                                if(j == h){
                                        continue;
                                }
                                int cost = d[i - 1][j] + (s[i] != v[h]);
                                if(cost < d[i][h]){
                                        d[i][h] = cost;
                                        p[i][h] = j;
                                }
                        }
                }
        }
        int h = 0;
        for(int i = 1; i < 3; i++){
                if(d[n][i] < d[n][h]){
                        h = i;
                }
        }
        cout << d[n][h] << "\n";
        string res = "";
        for(int i = n; i >= 1; i--){
                res += v[h];
                h = p[i][h];
        }
        reverse(res.begin(), res.end());
        cout << res << "\n";
}