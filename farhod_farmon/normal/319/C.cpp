#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100200;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
long long a[N];
long long b[N];
long long k[N];
vector < int > v;

long double inter(int i, int j)
{
        return 1.0 * (b[j] - b[i]) / (k[i] - k[j]);
}

void add(int i)
{
        while(v.size() > 1 && inter(v[v.size() - 2], i) < inter(v[v.size() - 2], v[v.size() - 1])){
                v.pop_back();
        }
        v.push_back(i);
}

long long get(long long x)
{
        int l = 0, r = v.size() - 1;
        while(l < r){
                int m = (l + r) / 2;
                if(inter(v[m], v[m + 1]) < x){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        return k[v[l]] * x + b[v[l]];
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> k[i];
        }
        for(int i = 2; i <= n; i++){
                add(i - 1);
                b[i] = get(a[i]);
        }
        cout << b[n] << "\n";
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