#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=3e5+13;
int a[maxn],n,b[maxn][19],m,d[maxn],c[maxn];
int qry(int l,int r){
    int len=d[r-l+1];
    return max(b[l][len],b[r-(1<<len)+1][len]);
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) a[i+n]=a[i],a[i+n+n]=a[i];
    m=n*3;
    for (int i=1;i<=m;i++) b[i][0]=a[i];
    for (int j=1;j<=18;j++)
        for (int i=1;i+(1<<j)-1<=m;i++)
            b[i][j]=max(b[i][j-1],b[i+(1<<(j-1))][j-1]);
    d[1]=0; for (int i=2;i<=m;i++) d[i]=d[i/2]+1;
    for (int i=1;i<=m;i++) c[i]=1e9;
    for (int i=1;i<=m;i++){
        if (qry(1,i)<=2*a[i]) continue;
        int l=1,r=i;
        while (r-l>1){
            int mid=(l+r)>>1;
            if (qry(mid,i)<=2*a[i]) r=mid; else l=mid;
        }
        c[l]=min(c[l],i);
    }
    for (int i=m-1;i;i--) c[i]=min(c[i],c[i+1]);
    for (int i=1;i<=n;i++){
        int ret=min({c[i]-i,c[i+n]-(i+n),c[i+n+n]-(i+n+n)});
        if (ret<=m) printf("%d ",ret); else printf("-1 ");
    }
    puts("");
    return 0;
}