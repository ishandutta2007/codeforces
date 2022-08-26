#include<bits/stdc++.h>
#define maxn 500005

using namespace std;
typedef pair<int,int> pi;
struct node{
    int x,y,z;
}ans[maxn];
set <int> a[maxn];
set <int> ::iterator ut,vt,tt;
pi c[maxn];
int n,k,res,r[maxn],b[maxn],cnt,p,q,sum,id[maxn],u,v;

int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        for (int j=0;j<b[i];j++){
            scanf("%d",&p);
            a[i].insert(p);
        }
        sum+=b[i];
        c[i]=(pi){b[i],i};
    }
    sort(c+1,c+n+1);
    for (int i=1;i<=n;i++) id[c[i].second]=i,r[i]=sum/n;
    for (int i=1;i<=n;i++) if (id[i]>n-sum%n) r[i]++;
    u=v=1;
    while (1){
        while (u<=n&&b[u]>=r[u]) u++;
        while (v<=n&&b[v]<=r[v]) v++;
        if (u>n||v>n) break;
        for (ut=a[u].begin(),vt=a[v].begin();;ut!=a[u].end()&&vt!=a[v].end()){
            while (ut!=a[u].end()&&(*ut)<(*vt)) ut++;
            if (ut==a[u].end()||(*ut)>(*vt)){
                ans[cnt++]=(node){v,u,(*vt)};
                tt=vt; vt++; a[u].insert(*tt); a[v].erase(tt);
                b[u]++; b[v]--;
            } else vt++;
            if (b[u]==r[u]||b[v]==r[v]) break;
        }
    }
    cout << cnt << endl;
    for (int i=0;i<cnt;i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
    return 0;
}