#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int k;
int v;
int a[N];
int d[N];
int c[N];
bool used[N];

void solve()
{
        cin >> n >> k >> v;
        used[0] = 1;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                int x = a[i] % k;
                if(x == 0){
                        continue;
                }
                vector < int > v;
                for(int j = 0; j < k; j++){
                        if(!used[j]){
                                continue;
                        }
                        int nj = (j + x) % k;
                        if(!used[nj]){
                                v.push_back(nj);
                        }
                }
                for(int x: v){
                        used[x] = 1;
                        d[x] = i;
                }
        }
        int need = v % k;
        if(used[need] == 0){
                cout << "NO" << "\n";
                return;
        }
        int gg = 0;
        while(need != 0){
                int g = d[need], x = a[g] % k;
                gg += x;
                c[g] = 1;
                need = (need - x);
                if(need < 0){
                        need += k;
                }
        }
        int fi = 1, se = 2;
        if(v % k > 0){
                for(int i = 1; i <= n; i++){
                        if(c[i] == 0){
                                se = i;
                        }
                        else{
                                fi = i;
                        }
                }

        }
        if(fi == se){
                if(se > 1){
                        se--;
                }
                else{
                        se++;
                }
        }
        vector < pair < int, pair < int, int > > > ans;
        for(int i = 1; i <= n; i++){
                if(c[i] == 1){
                        gg += a[i];
                }
                if(!a[i]){
                        continue;
                }
                if(c[i] == 0 && i != se){
                        ans.push_back({(a[i] - 1) / k + 1, {i, se}});
                        a[se] += a[i];
                        a[i] = 0;
                }
                if(c[i] == 1 && i != fi){
                        ans.push_back({(a[i] - 1) / k + 1, {i, fi}});
                        a[fi] += a[i];
                        a[i] = 0;
                }
        }
        need = v / k - a[fi] / k;
        int g = a[se] / k;
        //assert(a[fi] % k == v % k);
        if(need > 0){
                if(need > g){
                        cout << "NO" << "\n";
                        return;
                }
                ans.push_back({need, {se, fi}});
        }
        else if(need < 0){
                ans.push_back({-need, {fi, se}});
        }
        cout << "YES" << "\n";
        for(auto p: ans){
                cout << p.fi << " " << p.se.fi << " " << p.se.se << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}