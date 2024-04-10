#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 70070;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

string s;

bool f(string s)
{
        for(int i = 0; i < s.size(); i++){
                if(s[i] != s[s.size() - i - 1]){
                        return false;
                }
        }
        return true;
}

void solve()
{
        cin >> s;
        for(int i = 0; i < 10; i++){
                if(f(s)){
                        cout << "YES" << "\n";
                        return;
                }
                s = '0' + s;
        }
        cout << "NO" << "\n";
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}