#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 55;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int a[N];
int b[N];
char c[N][N];
vector < int > va[N], vb[N];

int ga(int x)
{
        if(x == a[x]){
                return x;
        }
        return a[x] = ga(a[x]);
}

int gb(int x)
{
        if(x == b[x]){
                return x;
        }
        return b[x] = gb(b[x]);
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i < N; i++){
                a[i] = b[i] = i;
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        for(int h = j + 1; h <= m; h++){
                                if(c[i][j] == '#' && c[i][h] == '#'){
                                        b[gb(j)] = gb(h);
                                }
                        }
                }
        }
        for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                        for(int h = j + 1; h <= n; h++){
                                if(c[j][i] == '#' && c[h][i] == '#'){
                                        a[ga(j)] = ga(h);
                                }
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                va[ga(i)].push_back(i);
        }
        for(int i = 1; i <= m; i++){
                vb[gb(i)].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(c[i][j] == '.'){
                                continue;
                        }
                        for(int x: va[ga(i)]){
                                for(int y: vb[gb(j)]){
                                        if(c[x][y] == '.'){
                                                cout << "No" << "\n";
                                                return;
                                        }
                                }
                        }
                }
        }
        cout << "Yes" << "\n";
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