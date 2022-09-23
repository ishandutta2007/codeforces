#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 10010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int b[N];
pair < int, int > a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        sort(a + 1, a + n + 1);
        b[a[1].se] = a[n].fi;
        for(int i = 2; i <= n; i++){
                b[a[i].se] = a[i - 1].fi;
        }
        for(int i = 1; i <= n; i++){
                cout << b[i] << " ";
        }
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