#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1 << 20;
const int mod = 998244353;

using namespace std;

int n;
int h, g;
int a[N];
long long S;
vector < int > res, v;

bool make(int x)
{
        v.clear();
        int l = x * 2, r = x * 2 + 1;
        v.push_back(x);
        while(l < n && r < n && (a[l] || a[r])){
                if(a[l] > a[r]){
                        v.push_back(l);
                        r = l * 2 + 1;
                        l = l * 2;
                } else{
                        v.push_back(r);
                        l = r * 2;
                        r = r * 2 + 1;
                }
        }
        if(v.back() < (1 << g)) return false;
        S -= a[x];

        for(int i = 1; i < v.size(); i++) a[v[i - 1]] = a[v[i]];
        a[v.back()] = 0;

        return true;
}

void solve()
{
        scanf("%d%d", &h, &g);
        S = 0;
        n = (1 << h);
        for(int i = 1; i < (1 << h); i++){
                scanf("%d", a + i);
                S += a[i];
        }

        res.clear();
        for(int i = 1; i < (1 << g); i++){
                while(make(i)) res.push_back(i);
        }
        printf("%lld\n", S);
        for(int x: res) printf("%d ", x);
        printf("\n");
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        scanf("%d", &t);
        while(t--) solve();

}