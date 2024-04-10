#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000*100+1;
const int INF = 1000*1000*1000+1;
const int MOD = 1000*1000*1000+7;
int n,r,k;
long long ans;
vector<int>V[MAXN];
bool visited[MAXN];

long long pow_mod(long long p,long long w) {
    long long res=1;
    while(w>0) {
        if(w&1) {
            res=(res*p)%MOD;
        }
        w/=2;
        p=(p*p)%MOD;
    }
    return res;
}

void dfs(int x) {
    r++;
    visited[x]=1;
    for(auto nbh:V[x]) if(!visited[nbh]) dfs(nbh);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int a,b,i=1; i<n;i++) {
        bool t;
        cin>>a>>b>>t;
        if(!t) {
            V[a].push_back(b);
            V[b].push_back(a);
        }
    }
    ans = pow_mod(n,k);
    for(int i=1; i<=n;i++) {
        if(!visited[i]) {
            r=0;
            dfs(i);
            ans -= pow_mod(r,k);
            if(ans<0) ans+=MOD*2;
            ans=ans%MOD;
        }
    }
    cout<<ans;
}