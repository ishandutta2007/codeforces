#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100005],b[100005],s[100005],l,r,f[100005][21],g[100005][21];
int q(int l,int r){
    int k=log2(r-l+1);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
int q2(int l,int r){
    int k=log2(r-l+1);
    return min(g[l][k],g[r-(1<<k)+1][k]);
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(register int i=1;i<=n;i++)cin>>a[i];
    for(register int i=1;i<=n;i++)cin>>b[i],a[i]-=b[i],s[i]=s[i-1]+a[i],f[i][0]=s[i],g[i][0]=s[i];
    for(int j=1;j<=21;j++)
    for(int i=1;i+(1<<j)-1<=n;i++)f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int j=1;j<=21;j++)
    for(int i=1;i+(1<<j)-1<=n;i++)g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
    while(m--){
        cin>>l>>r;
        if(s[l-1]!=s[r]||s[l-1]<q(l,r))cout<<"-1\n";
        else cout<<s[l-1]-q2(l,r)<<endl;
    }
    return 0;
}