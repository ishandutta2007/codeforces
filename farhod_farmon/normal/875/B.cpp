#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
set < int > s;

void solve()
{
        cin >> n;
        cout << 1 << " ";
        for(int i = 1; i <= n; i++){
                s.insert(i);
        }
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                s.erase(x);
                if(s.empty()){
                        cout << 1 << " ";
                }
                else{
                        cout << 1 + *(--s.end()) - (n - i) << " ";
                }
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