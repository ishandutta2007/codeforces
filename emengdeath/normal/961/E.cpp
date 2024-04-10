#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int f[N*4],c[N],a[N],g[N],e[N*2][2];
long long ans;
int n;
void ins(int x,int y){
    static int sum=0;
    e[++sum][0]=y,e[sum][1]=g[x],g[x]=sum;
}
void ins(int l,int r,int s,int ll,int v){
    f[s]+=v;
    if (l==r)return;
    if ((l+r)/2>=ll)ins(l,(l+r)/2,s+s,ll,v);
    else
        ins((l+r)/2+1,r,s+s+1,ll,v);
}
void get(int l,int r,int s,int ll){
    if (!f[s]||ll<l)return;
    if (ll>=r){
        ans+=f[s];
        return;
    }
    get(l,(l+r)/2,s+s,ll),get((l+r)/2+1,r,s+s+1,ll);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i],a[i]=min(a[i],n);
    for (int i=1;i<=n;i++){
        if (min(max(a[i]+1,i),n+1)==i){
            for (int j=g[i];j;j=e[j][1])
                ins(1,n,1,e[j][0],-1);
            get(1,n,1,a[i]);
        }else{
            for (int j=g[i];j;j=e[j][1])
                ins(1,n,1,e[j][0],-1);
            ins(min(max(a[i]+1,i),n+1),i);
            get(1,n,1,a[i]);
            ins(1,n,1,i,1);
        }
    }
    cout<<ans;
    return 0;
}