#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+3;
const int E=200000;
struct node{
    int l,r,val;
}b[maxn];
bool cmp(node u,node v){
    return u.l<v.l;
}
int m,n,q,a[maxn],ans,l[maxn],r[maxn],cnt[maxn];

int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=E;i++) l[i]=r[i]=-1;
    for (int i=1;i<=n;i++){
        if (l[a[i]]==-1) l[a[i]]=i;
        r[a[i]]=i; cnt[a[i]]++;
    }
    for (int i=1;i<=E;i++) if (l[i]!=-1) b[++m]=(node){l[i],r[i],cnt[i]};
    sort(b+1,b+m+1,cmp);
    for (int i=1;i<=m;i++){
        int mx,sum,R;
        mx=sum=b[i].val; R=b[i].r;
        while (i+1<=m&&b[i+1].l<=R){
            i++;
            sum+=b[i].val; mx=max(mx,b[i].val);
            R=max(R,b[i].r);
        }
        ans+=sum-mx;
    }
    cout << ans << endl;
}