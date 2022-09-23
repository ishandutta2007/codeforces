#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 10010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

long long a, b, c;
string s;

void solve()
{
        cin >> s;
        for(int i = 0; i < s.size(); i++){
                if(s[i] == 'Q'){
                        a += 1;
                        c += b;
                }
                else if(s[i] == 'A'){
                        b += a;
                }
        }
        cout << c << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}