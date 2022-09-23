#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 9;

using namespace std;

int n;
int p[N];
int c[N];
int f[N];
long long S;
vector < int > v[N], g[N];

bool solve(int oq)
{
        long long s = S;
        for(int i = 1; i <= n; i++){
                p[i] = i - 1;
                c[i - 1] = 1;
                s -= i;
                v[i].clear();
                g[i].clear();
        }
        c[n] = 0;
        v[n].push_back(n);
        for(int i = 1; i <= n; i++){
                if(c[i] < oq){
                        g[i].push_back(i);
                }
        }
        int l = 1, r = n;
        while(s){
                while(l < r && v[r].empty()){
                        r--;
                }
                while(l < r && g[l].empty()){
                        l++;
                }
                if(r - l - 1 <= 0){
                        return false;
                }
                int x = v[r].back(), y = g[l].back();
                if(s + r - l - 1 > 0){
                        while(l < r && s + r - l - 1 > 0){
                                l += 1;
                        }
                        if(r - l - 1 <= 0){
                                return false;
                        }
                        y = g[l].back();
                }
                v[r].pop_back();
                s += r - l - 1;
                c[y] += 1;
                c[p[x]] -= 1;
                if(c[p[x]] == 0){
                        v[r - 1].push_back(p[x]);
                }
                if(c[y] == oq){
                        g[l].pop_back();
                }
                p[x] = y;
                g[l + 1].push_back(x);
        }
        return s == 0;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> S;
        long long s = S;
        if(s < n + n - 1){
                cout << "No" << "\n";
                return 0;
        }
        int l = 1, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(solve(m)){
                        r = m;
                }
                else{
                        l = m + 1;
                }
        }
        if(l == n){
                cout << "No" << "\n";
                return 0;
        }
        solve(l);
        cout << "Yes" << "\n";
        for(int i = 2; i <= n; i++){
                cout << p[i] << " ";
        }
}