#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000200;
const long long mod = 1000000007;

using namespace std;

int n;
int k;
int a[N];
int r[N];
int d[N];
int p[N];
int dip[N];
multiset < int > s[N];
vector < int > g[N];
multiset < int > res;

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

int best(int x)
{
        if(s[x].empty()){
                return 1;
        }
        return dip[x] - *s[x].begin() + 1;
}

void add(int x)
{
        if(r[x]){
                g[r[x]].push_back(x);
        }
        s[x].insert(dip[x]);
        for(int y: g[x]){
                if(x - y >= k){
                        continue;
                }
                int py = get(y);
                res.erase(res.find(best(py)));
                if(s[py].size() > s[x].size()){
                        swap(s[x], s[py]);
                }
                for(int z: s[py]){
                        s[x].insert(z);
                }
                s[py].clear();
                p[py] = x;
        }
        res.insert(best(x));
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++){
                scanf("%d", &a[i]);
        }
        vector < int > v;
        for(int i = n; i >= 1; i--){
                p[i] = i;
                while(!v.empty() && a[i] >= a[v.back()]){
                        v.pop_back();
                }
                if(!v.empty()){
                        r[i] = v.back();
                        dip[i] = dip[r[i]] - 1;
                }
                v.push_back(i);
        }
        for(int i = 1; i <= k; i++){
                add(i);
        }
        printf("%d ", *(--res.end()));
        for(int i = 1; i <= n - k; i++){
                int x = get(i);
                res.erase(res.find(best(x)));
                if(x != i){
                        s[x].erase(s[x].find(dip[i]));
                        res.insert(best(x));
                }
                add(i + k);
                printf("%d ", *(--res.end()));
        }
}