#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2002 * 50;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
string s, t;

void solve()
{
        cin >> n >> m >> s >> t;
        int h = -1;
        for(int i = 0; i < n; i++){
                if(s[i] == '*'){
                        h = i;
                        break;
                }
        }
        if(h == -1){
                if(s == t){
                        cout << "YES" << "\n";
                }
                else{
                        cout << "NO" << "\n";
                }
                return;
        }
        if(n - 1 > m){
                cout << "NO" << "\n";
                return;
        }
        for(int i = 0; i < h; i++){
                if(s[i] != t[i]){
                        cout << "NO" << "\n";
                        return;
                }
        }
        for(int i = n - 1; i > h; i--){
                if(s[i] != t[m - (n - i)]){
                        cout << "NO" << "\n";
                        return;
                }
        }
        cout << "YES" << "\n";
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