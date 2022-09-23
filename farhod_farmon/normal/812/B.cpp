#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int d[N][2];
char c[N][N];
int l[N];
int r[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m + 2; j++){
                        cin >> c[i][j];
                }
        }
        for(int i = 1; i <= n / 2; i++){
                for(int j = 1; j <= m + 2; j++){
                        swap(c[n - i + 1][j], c[i][j]);
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m + 2; j++){
                        if(c[i][j] == '1'){
                                if(l[i] == 0){
                                        l[i] = j;
                                }
                                r[i] = j;
                        }
                }
        }
        while(n > 0){
                bool cler = true;
                for(int j = 1; j <= m + 2; j++){
                        if(c[n][j] == '1'){
                                cler = false;
                        }
                }
                if(cler == false){
                        break;
                }
                n--;
        }
        d[0][1] = m + 1;
        for(int i = 1; i <= n; i++){
                if(l[i] == 0){
                        d[i][0] = d[i - 1][0] + (i > 1);
                        d[i][1] = d[i - 1][1] + (i > 1);
                        continue;
                }
                d[i][0] = min(d[i - 1][1] + (i < n ? m + 1 : (m + 2 - l[i])), d[i - 1][0] + (1 + (i < n)) * (r[i] - 1)) + (i > 1);
                d[i][1] = min(d[i - 1][0] + (i < n ? m + 1 : r[i] - 1), d[i - 1][1] + (1 + (i < n)) * (m + 2 - l[i])) + (i > 1);
        }
        cout << min(d[n][0], d[n][1]) << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("curling.in");
        //fout("curling.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}