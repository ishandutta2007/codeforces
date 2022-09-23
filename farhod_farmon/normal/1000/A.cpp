#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1110;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int d1[200][200];
int d2[200][200];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                d1[s.size()][s[s.size() - 1]]++;
        }
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                d2[s.size()][s[s.size() - 1]]++;
        }
        int cnt = 0;
        for(int i = 0; i < 200; i++){
                for(int j = 0; j < 200; j++){
                        cnt += max(0, d2[i][j] - d1[i][j]);
                }
        }
        cout << cnt << "\n";
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