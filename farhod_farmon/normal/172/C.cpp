#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

long long n, m;
long long t[N];
long long x[N];
long long a[N];
long long used[N];

long long solve(long long l, long long r, long long L)
{
    vector < pair < long long, long long > > v;
    for(long long i = l; i <= r; i++){
        v.pb({x[i], i});
        used[x[i]] = 0;
    }
    v.pb({0, 0});
    sort(v.begin(), v.end());
    for(long long i = 1; i < v.size(); i++){
        long long j = i;
        long long cnt = 0;
        while(j < v.size() && v[i].fi == v[j].fi){
            cnt++;
            j++;
        }
        L += v[i].fi - v[i - 1].fi;
        for(long long h = i; h < j; h++)
            a[v[h].se] = L;
        L += cnt / 2 + 1;
        i = j - 1;
    }
    return L + v.back().fi;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++)
        cin >> t[i] >> x[i];
    long long l = 0;
    for(long long i = 1; i <= n; i += m)
        l = solve(i, min(i + m - 1, n), max(l, t[min(i + m - 1, n)]));
    for(long long i = 1; i <= n; i++)
        cout << a[i] << " ";
}