#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int a[N];
int b[N];
int c[N][N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int j = 1; j <= m; j++){
                cin >> b[j];
        }
        for(int h = 0; h < 30; h++){
                vector < int > v1, v2;
                for(int i = 1; i <= n; i++){
                        if(a[i] & (1 << h)){
                                v1.push_back(i);
                        }
                }
                for(int i = 1; i <= m; i++){
                        if(b[i] & (1 << h)){
                                v2.push_back(i);
                        }
                }
                int l = min((int)v1.size(), (int)v2.size());
                for(int i = 0; i < l; i++){
                        c[v1[i]][v2[i]] |= (1 << h);
                }
                if(((int)v1.size() - l) % 2 || ((int)v2.size() - l) % 2){
                        cout << "NO" << "\n";
                        return;
                }
                for(int i = l; i < v1.size(); i += 2){
                        c[v1[i]][1] |= (1 << h);
                        c[v1[i + 1]][1] |= (1 << h);
                }
                for(int i = l; i < v2.size(); i += 2){
                        c[1][v2[i]] |= (1 << h);
                        c[1][v2[i + 1]] |= (1 << h);
                }
        }
        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cout << c[i][j] << " ";
                }
                cout << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}