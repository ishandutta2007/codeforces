#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400200;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

string s;

void solve()
{
        cin >> s;
        int f0 = 0, f1 = 0, h;
        for(int i = 0; i <= s.size(); i++){
                if(i == s.size() || s[i] == '2'){
                        h = i;
                        break;
                }
                if(s[i] == '0'){
                        f0++;
                }
                else{
                        f1++;
                }
        }
        for(int i = h; i < s.size(); i++){
                if(s[i] == '1'){
                        f1++;
                }
        }
        for(int i = 0; i < f0; i++){
                cout << '0';
        }
        for(int i = 0; i < f1; i++){
                cout << '1';
        }
        for(int i = h; i < s.size(); i++){
                if(s[i] != '1'){
                        cout << s[i];
                }
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