#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int k2;
int a[N];
int b[N];
set < pair < long long, int > > s;

void solve()
{
        cin >> n >> k >> k2;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                s.insert({abs(a[i] - b[i]), i});
        }
        k += k2;
        long long ans = 0;
        while(k){
                k--;
                auto p = *(--s.end());
                s.erase(p);
                p.fi = abs(p.fi - 1);
                s.insert(p);
        }
        while(!s.empty()){
                auto p = *s.begin();
                s.erase(s.begin());
                ans += p.fi * p.fi;
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