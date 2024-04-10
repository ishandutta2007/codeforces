#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
vector < int > v;

void solve()
{
        cin >> n;
        for(int i = 2; i <= n; i += 2){
                v.push_back(i);
        }
        for(int i = 1; i <= n; i += 2){
                v.push_back(i);
        }
        for(int i = 2; i <= n; i += 2){
                v.push_back(i);
        }
        cout << v.size() << "\n";
        for(int x: v){
                cout << x << " ";
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