#include<bits/stdc++.h>
#define maxn 2304939

using namespace std;
typedef long long ll;
int n,m,pre[maxn],cnt,u,v,q;
int ffind(int x){
    if (pre[x]!=x) pre[x]=ffind(pre[x]);
    return pre[x];
}
void union_(int x,int y){
    pre[x]=y;
}
int main(){
    cin >> n >> m >> q;
    for (int i=1;i<=n+m;i++) pre[i]=i;
    cnt=n+m-1;
    while (q--){
        scanf("%d%d",&u,&v); v+=n;
        u=ffind(u); v=ffind(v);
        if (u!=v) union_(u,v),cnt--;
    }
    cout << cnt << endl;
}