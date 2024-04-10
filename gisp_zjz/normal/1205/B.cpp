#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
ll n,m,d[125],ans;
queue <ll> q;
vector <ll> a,h[125];
int main(){
    cin >> n;
    while (n--){
        cin >> m;
        if (m>0) a.pb(m);
    }
    n=a.size(); ans=n+1;
    if (n>120){puts("3");return 0;}
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i!=j&&(a[i]&a[j])>0) h[i].pb(j);
    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++) if (a[i]&a[j]){
        memset(d,-1,sizeof(d));
        d[i]=0; q.push(i);
        while (!q.empty()){
            ll u=q.front(); q.pop();
            for (auto v:h[u]){
                if (u==i&&v==j) continue;
                if (d[v]==-1) d[v]=d[u]+1,q.push(v);
            }
        }
        if (d[j]!=-1) ans=min(ans,d[j]+1);
    }
    if (ans<=n) cout << ans << endl; else puts("-1");
    return 0;
}