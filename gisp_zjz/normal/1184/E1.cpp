#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+3;
struct edge{
    int u,v,w;
};
bool cmp(edge x,edge y){
    return x.w<y.w;
}
edge a[maxn];
int pre[maxn],n,m,ans;
int ffind(int x){
    if (pre[x]==x) return x;
    pre[x]=ffind(pre[x]);
    return pre[x];
}
int main(){
    cin >> n >> m;
    for (int i=0;i<m;i++) cin >> a[i].u >> a[i].v >> a[i].w;
    for (int i=1;i<=n;i++) pre[i]=i;
    sort(a+1,a+m,cmp);
    ans=1000000000;
    for (int i=1;i<m;i++){
        int u=ffind(a[i].u),v=ffind(a[i].v);
        if (u!=v) pre[u]=v;
        if (ffind(a[0].u)==ffind(a[0].v)) {
            ans=a[i].w;
            break;
        }
    }
    cout << ans << endl;
}