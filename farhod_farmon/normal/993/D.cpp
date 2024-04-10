#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 55;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
long double d[N];
long double f[N];
pair < long double, long double > p[N];

bool can(long double m)
{
        for(int i = 0; i < N; i++){
                d[i] = f[i] = -1e17;
        }
        d[0] = 0;
        for(int i = 1; i <= n; ){
                vector < long double > v;
                int gg = 0;
                while(i + gg <= n && p[i + gg].fi == p[i].fi){
                        v.push_back(p[i + gg].se * m - p[i + gg].fi);
                        gg++;
                }
                sort(v.begin(), v.end());
                reverse(v.begin(), v.end());
                for(int i = 1; i < v.size(); i++){
                        v[i] += v[i - 1];
                }
                for(int j = 0; j < N; j++){
                        if(d[j] < -1e16){
                                continue;
                        }
                        for(int h = 0; h <= v.size(); h++){
                                if(h > j){
                                        break;
                                }
                                if(h == v.size()){
                                        f[j - h] = max(f[j - h], d[j]);
                                }
                                else{
                                        int nj = j - h + (v.size() - h);
                                        f[nj] = max(f[nj], d[j] + v[v.size() - h - 1]);
                                }
                        }
                }
                for(int j = 0; j < N; j++){
                        d[j] = f[j];
                        f[j] = -1e17;
                }
                i += gg;
        }
        for(int i = 0; i < N; i++){
                if(d[i] >= 0){
                        return true;
                }
        }
        return false;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> p[i].fi;
        }
        for(int i = 1; i <= n; i++){
                cin >> p[i].se;
        }
        sort(p + 1, p + n + 1);
        reverse(p + 1, p + n + 1);
        long double l = 0.0, r = 1e12;
        for(int i = 0; i < 200; i++){
                long double m = (l + r) / 2;
                if(can(m)){
                        r = m;
                }
                else{
                        l = m;
                }
        }
        l *= 1000;
        long double ans = (long long)(l);
        while(ans < l){
                ans++;
        }
        cout << (long long)(ans + 0.1) << "\n";
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