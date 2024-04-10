#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
const long long mod=1e9+7;
int n,m;
int a[N],b[N];
struct node{
    int l,x,wz;
}q[N];
int ans[N];
bool cmp(const node&a,const node&b){
    return a.l<b.l;
}
long long power(long long x,long long y){
    long long z=1;
    while (y){
        if (y&1)(z*=x)%=mod;
        (x*=x)%=mod,y>>=1;
    }
    return z;
}
int main(){
    ios::sync_with_stdio();
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>q[i].l>>q[i].x,q[i].wz=i;
    sort(q+1,q+m+1,cmp);
    int L=0;
    for (int i=1;i<=m;i++){
        while (L<q[i].l){
            ++L;
            for (int j=b[0];j;j--)
                if ((a[L]^b[j])<a[L])a[L]^=b[j];
            if (a[L])b[++b[0]]=a[L];
            sort(b+1,b+b[0]+1);
        }
        for (int j=b[0];j;j--)
            if ((q[i].x^b[j])<q[i].x)q[i].x^=b[j];
        if (!q[i].x)
            ans[q[i].wz]=power(2,L-b[0]);           
    }
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}