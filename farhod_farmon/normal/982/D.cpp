#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int f[N];
int len[N];
pair < int, int > p[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                p[i] = {a[i], i};
        }
        int ans = 1, best = 0;
        sort(p + 1, p + n + 1);
        set < pair < int, int > > s;
        for(int ii = 1; ii <= n; ii++){
                int i = p[ii].se, l = i, r = i;
                if(i + 1 <= n && f[i + 1]){
                        s.erase({len[i + 1], i + 1});
                        r = i + len[i + 1];
                }
                if(i - 1 >= 1 && f[i - 1]){
                        s.erase({len[f[i - 1]], f[i - 1]});
                        l = i - len[f[i - 1]];
                }
                f[l] = f[r] = l;
                len[l] = r - l + 1;
                s.insert({len[l], l});
                if(s.begin()->fi == (--s.end())->fi){
                        if(s.size() > best){
                                best = s.size();
                                ans = a[i] + 1;
                        }
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}