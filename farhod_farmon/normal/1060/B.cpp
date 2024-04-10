#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

long long x;
vector < long long > v;

void solve()
{
        cin >> x;
        long long y = x;
        while(y > 0){
                v.push_back(y % 10);
                y /= 10;
        }
        vector < long long > a, b;
        y = 0;
        for(int i = 0; i < v.size() - 1; i++){
                a.push_back(9);
                y = y * 10ll + 9;
        }
        long long ans = (v.size() - 1) * 9;
        x -= y;
        while(x > 0){
                ans += x % 10;
                x /= 10;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}