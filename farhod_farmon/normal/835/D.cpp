#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
int k[N];
int a[N][N];
int d[N][N];
bool p[N][N];
string s;

bool P(int l, int r)
{
        return p[l][r];
}

void solve()
{
        cin >> s;
        n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        for(int i = n - 1; i >= 0; i--){
                for(int j = n - 1; j >= 0; j--){
                        if(s[i] == s[j]){
                                a[i][j] = a[i + 1][j + 1] + 1;
                        }
                        if(i == j){
                                p[i][j] = 1;
                        }
                        else if(s[i] == s[j] && (i + 1 == j || p[i + 1][j - 1])){
                                p[i][j] = 1;
                        }
                }
        }
        for(int i = n - 1; i >= 0; i--){
                for(int j = i; j < n; j++){
                        k[1] += P(i, j);
                        d[i][j] = P(i, j);
                        if(i == j){
                                continue;
                        }
                        int g = (j - i + 1) / 2;
                        int mn = min(d[i][i + g - 1], d[j - g + 1][j]);
                        if(a[i][j - g + 1] >= g){
                                d[i][j] = mn + 1;
                        }
                        if(d[i][j] <= 1){
                                d[i][j] = P(i, j);
                        }
                        else{
                                k[d[i][j]]++;
                        }
                }
        }
        for(int i = n; i >= 2; i--){
                k[i] += k[i + 1];
        }
        for(int i = 1; i <= n; i++){
                cout << k[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}