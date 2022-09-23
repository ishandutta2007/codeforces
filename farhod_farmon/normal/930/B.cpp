#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int c[N][200];
string s[N];
int best[N];
vector < int > v[200];

void solve()
{
        cin >> s[0];
        n = s[0].size();
        for(int i = 1; i < n; i++){
                for(int j = 1; j < n; j++){
                        s[i] += s[i - 1][j];
                }
                s[i] += s[i - 1][0];
        }
        for(int i = 0; i < n; i++){
                v[s[i][0]].push_back(i);
        }
        int ans = 0;
        for(int h = 'a'; h <= 'z'; h++){
                for(int i = 1; i < n; i++){
                        for(int j = 'a'; j <= 'z'; j++){
                                c[i][j] = 0;
                        }
                }
                for(int x: v[h]){
                        for(int i = 1; i < n; i++){
                                c[i][s[x][i]]++;
                        }
                }
                for(int x: v[h]){
                        for(int i = 1; i < n; i++){
                                if(c[i][s[x][i]] == 1){
                                        best[i]++;
                                }
                        }
                }
                int mx = 0;
                for(int i = 0; i < n; i++){
                        mx = max(mx, best[i]);
                        best[i] = 0;
                }
                ans += mx;
        }
        cout << fixed << setprecision(9) << 1.0 * ans / n << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}