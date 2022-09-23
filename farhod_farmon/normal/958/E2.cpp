#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
bool used[N];
long long a[N];
long long d[N / 10];
long long t[N / 10];

void solve()
{
        cin >> k >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        vector < pair < int, int > > v;
        for(int i = 1; i < n; i++){
                v.push_back({a[i + 1] - a[i], i});
        }
        sort(v.begin(), v.end());
        int l = v.size();
        l = min(l, k + k + k);
        for(int i = 0; i < l; i++){
                used[v[i].se] = 1;
                used[v[i].se + 1] = 1;
        }
        int new_n = 0;
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        new_n++;
                        a[new_n] = a[i];
                }
        }
        n = new_n;
        d[0] = d[1] = 1e18;
        for(int i = 2; i <= n; i++){
                d[i] = min(d[i - 1], a[i] - a[i - 1]);
        }
        for(int i = 0; i <= n; i++){
                t[i] = 1e18;
        }
        for(int i = 2; i <= k; i++){
                for(int j = i * 2; j <= n; j++){
                        t[j] = min(t[j - 1], d[j - 2] + a[j] - a[j - 1]);
                }
                for(int j = 0; j <= n; j++){
                        d[j] = t[j];
                        t[j] = 1e18;
                }
        }
        cout << d[n] << "\n";
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