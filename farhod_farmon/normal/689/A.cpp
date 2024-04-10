#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int p[4][3] = {{1, 2, 3},
               {4, 5, 6},
               {7, 8, 9},
               {-1, 0, -1}
              };

pair < int, int > in[10];

int main()
{
    //freopen( "angry.in", "r", stdin );
    //freopen( "angry.out", "w", stdout );
    //fin
    //fout
    vector < pair < int, int > > v[8];
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        s[i] -= '0';
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(p[i][j] != -1)
                in[p[i][j]] = {i, j};
        }
    }
    int g = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(!i && !j)
                continue;
            for(int h = 0; h < n; h++){
                v[g].pb(in[s[h]]);
                v[g].back().fi += i;
                v[g].back().se += j;
            }
            g++;
        }
    }
    for(int i = 0; i < g; i++){
        bool b = true;
        for(int j = 0; j < n; j++){
            if(v[i][j].fi < 0 || v[i][j].fi >= 4 || v[i][j].se < 0 || v[i][j].se >= 3 || p[v[i][j].fi][v[i][j].se] == -1){
                b = false;
            }
        }
        if(b){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}