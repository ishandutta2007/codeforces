#include<bits/stdc++.h>
#define maxn 234856

using namespace std;
typedef long long ll;
vector <ll> h[maxn];
ll n,m,ans,res,s,c[maxn],b[maxn],cc;

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++){
        ll u,v;
        scanf("%I64d%I64d",&u,&v);
        h[u].push_back(v); c[u]++;
    }
    for (int i=1;i<=m;i++) sort(h[i].begin(),h[i].end());
    ans=1e14;
    for (int i=1;i<=n/2+1;i++){
        s=0; res=h[1].size(); cc=0;
        for (int j=2;j<=m;j++) if (c[j]>i-1){
            for (int k=0;k<c[j]-(i-1);k++)
                s+=h[j][k],res++;
            for (int k=c[j]-(i-1);k<c[j];k++) b[cc++]=h[j][k];
        }
        else for (int k=0;k<c[j];k++) b[cc++]=h[j][k];
        if (res<i){
            sort(b,b+cc);
            for (int j=0;j<i-res;j++) s+=b[j];
        }
        ans=min(ans,s);
    }
    cout << ans << endl;
}