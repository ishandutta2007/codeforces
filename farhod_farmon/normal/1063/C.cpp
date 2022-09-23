#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

pair < int, int > solve1(int n)
{
        int l = 0, r = 1e9;
        for(int i = 1; i <= n; i++){
                string s;
                int m = (l + r) / 2;
                cout << 1 << " " << m << endl;
                cin >> s;
                if(s[0] == 'b'){
                        l = m + 1;
                }
                else{
                        r = m - 1;
                }
        }
        return {1, (l + r) / 2};
}

pair < int, int > solve2(int n)
{
        int l = 0, r = 1e9;
        for(int i = 1; i <= n; i++){
                string s;
                int m = (l + r) / 2;
                cout << m << " " << 1000000000 << endl;
                cin >> s;
                if(s[0] == 'b'){
                        r = m - 1;
                }
                else{
                        l = m + 1;
                }
        }
        return {(l + r) / 2, 1000000000};
}

void solve()
{
        int n;
        cin >> n;
        if(n == 1){
                string s;
                cout << 1 << " " << 1 << endl;
                cin >> s;
                cout << 2 << " " << 2 << " " << 3 << " " << 2 << endl;
                return;
        }
        auto p = solve1(n / 2);
        auto t = solve2(n - n / 2);
        cout << p.fi << " " << p.se << " " << t.fi << " " << t.se << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("distance.in");
        //fout("distance.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}