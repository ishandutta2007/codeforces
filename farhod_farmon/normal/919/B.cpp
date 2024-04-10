#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5005;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int k;

bool f(int x)
{
        int cnt = 0;
        while(x){
                cnt += x % 10;
                x /= 10;
        }
        return cnt == 10;
}

void solve()
{
        vector < int > v;
        cin >> k;
        for(int i = 19; (int)v.size() < 10000; i++){
                if(f(i)){
                        v.push_back(i);
                }
        }
        cout << v[k - 1] << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}