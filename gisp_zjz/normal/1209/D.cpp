#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1234556;
int n,pre[maxn],cnt,m;
int ffind(int x){
    if (pre[x]==x) return x;
    pre[x]=ffind(pre[x]);
    return pre[x];
}

int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) pre[i]=i;
    for (int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        u=ffind(u); v=ffind(v);
        if (u==v) cnt++; else pre[v]=u;
    }
    cout << cnt << endl;
}