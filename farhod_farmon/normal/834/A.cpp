#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3030;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int f(char c)
{
        if(c == 'v'){
                return 0;
        }
        if(c == '<'){
                return 1;
        }
        if(c == '^'){
                return 2;
        }
        if(c == '>'){
                return 3;
        }
}

int n;
char x, y;

void solve()
{
        cin >> x >> y >> n;
        if(n % 2 == 0){
                cout << "undefined" << "\n";
        }
        else if((f(x) + n) % 4 == f(y)){
                cout << "cw" << "\n";
        }
        else{
                cout << "ccw" << "\n";
        }
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