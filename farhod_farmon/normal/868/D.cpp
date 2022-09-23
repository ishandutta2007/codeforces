#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 220;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
string s[N];
set < pair < int, int > > t[N];

void press(string &x)
{
        if(x.size() < 26){
                return;
        }
        string y = "";
        for(int i = 0; i < 13; i++){
                y += x[i];
        }
        for(int i = 0; i < 13; i++){
                y += x[x.size() - 13 + i];
        }
        x = y;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> s[i];
                for(int j = 0; j < s[i].size(); j++){
                        s[i][j] -= '0';
                }
                for(int j = 0; j < s[i].size(); j++){
                        int x = 0;
                        for(int h = j; h < s[i].size(); h++){
                                if(h - j == 11){
                                        break;
                                }
                                x = x * 2 + s[i][h];
                                t[i].insert({h - j, x});
                        }
                }
                press(s[i]);
        }
        cin >> m;
        m += n;
        for(int i = n + 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                for(int j = 0; j < s[x].size(); j++){
                        int f = 0;
                        for(int h = j; h < s[x].size(); h++){
                                f = f * 2 + s[x][h];
                        }
                        for(int h = 0; h < s[y].size(); h++){
                                f = f * 2 + s[y][h];
                                t[i].insert({s[x].size() - j + h, f});
                        }
                }
                s[i] = s[x] + s[y];
                for(auto p: t[x]){
                        t[i].insert(p);
                }
                for(auto p: t[y]){
                        t[i].insert(p);
                }
                press(s[i]);
                int k = 0;
                for(int j = 1; j < 12; j++){
                        bool can = true;
                        for(int h = 0; h < (1 << j); h++){
                                if(t[i].find({j - 1, h}) == t[i].end()){
                                        can = false;
                                        break;
                                }
                        }
                        if(can){
                                k = j;
                        }
                        else{
                                break;
                        }
                }
                cout << k << "\n";
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