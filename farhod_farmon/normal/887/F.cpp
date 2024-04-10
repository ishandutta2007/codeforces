#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
int k;
int s[N];
int a[N];
int f[N];
int L[N];
int t[19][N];

int get(int l, int r)
{
        if(r > n){
                return -1;
        }
        int g = L[r - l + 1];
        return min(t[g][l], t[g][r - (1 << g) + 1]);
}

void solve()
{
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                t[0][i] = a[i];
        }
        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n; j++){
                        if(j + (1 << i) - 1 <= n){
                                t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << i) / 2]);
                        }
                }
        }
        int st = -1;
        for(int i = 1; i <= n; i++){
                if(i + k > n || get(i + 1, i + k) < a[i]){
                        f[i] = 0;
                }
                else{
                        f[i] = 1;
                        if(st == -1){
                                st = i;
                        }
                }
                s[i] = s[i - 1] + f[i];
        }
        if(st == -1){
                cout << "YES" << "\n";
                return;
        }
        vector < pair < int, int > > v;
        for(int i = st + k; i > st; i--){
                if(f[i] == 1){
                        break;
                }
                v.push_back({a[i], get(i + 1, i + k)});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++){
                v[i].se = min(v[i].se, v[i - 1].se);
        }
        for(int i = st + k + 1; i <= n; i++){
                if(s[n] - s[i] > 0 || s[i - 1] - s[st + k] > 0 || a[i] >= a[st]){
                        continue;
                }
                if(v.empty() || v[0].fi <= a[i]){
                        continue;
                }
                int l = 0, r = v.size() - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(v[m + 1].fi > a[i]){
                                l = m + 1;
                        }
                        else{
                                r = m;
                        }
                }
                if(v[l].se < a[i]){
                        cout << "YES" << "\n";
                        return;
                }
        }
        cout << "NO" << "\n";
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