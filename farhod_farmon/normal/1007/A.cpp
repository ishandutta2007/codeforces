#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
set < pair < int, int > > s;

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s.insert({a[i], i});
    }
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        auto p = s.lower_bound({a[i] + 1, 0});
        if(p != s.end()){
            cnt++;
            s.erase(p);
        }
    }
    cout << cnt << "\n";
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