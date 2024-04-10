#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 111;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
string s[N];

void solve()
{
        int cnt = 0;
        cin >> n >> k;
        vector < pair < int, pair < int, int > > > v;
        for(int i = 1; i <= n; i++){
                cin >> s[i];
                for(int j = 0; j < 12; j++){
                        if(s[i][j] == '.'){
                                int x = 0;
                                if(j - 1 >= 0 && s[i][j - 1] == 'S'){
                                        x++;
                                }
                                if(j + 1 < 12 && s[i][j + 1] == 'S'){
                                        x++;
                                }
                                v.push_back({x, {i, j}});
                        }
                        else if(s[i][j] == 'S'){
                                if(j - 1 >= 0 && (s[i][j - 1] == 'P' || s[i][j - 1] == 'S')){
                                        cnt++;
                                }
                                if(j + 1 < 12 && (s[i][j + 1] == 'P' || s[i][j + 1] == 'S')){
                                        cnt++;
                                }
                        }
                }
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < k; i++){
                cnt += v[i].fi;
                s[v[i].se.fi][v[i].se.se] = 'x';
        }
        cout << cnt << "\n";
        for(int i = 1; i <= n; i++){
                cout << s[i] << "\n";
        }
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