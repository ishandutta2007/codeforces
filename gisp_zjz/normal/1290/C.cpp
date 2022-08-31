#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,bool> pi;
const int maxn=3e5+10;
int pre[maxn],sz[maxn],sz2[maxn],ans,n,k,choose[maxn],f[maxn];
char s[maxn];
vector <int> a[maxn];
bool op[maxn];
int qry(int x){
    if (choose[x]==0) return sz2[x];
    else if (choose[x]==1) return sz[x]-sz2[x];
    else return min(sz2[x],sz[x]-sz2[x]);
}
pi ffind(int x){
    if (pre[x]==x) return (pi){x,0};
    pi tmp=ffind(pre[x]);
    pre[x]=tmp.F;
    op[x]^=tmp.S;
    return (pi){pre[x],op[x]};
}
void _union(int x,int y,int o){
    pre[y]=x;
    if (o==0){
        op[y]=0;
        if (choose[x]==-1) choose[x]=choose[y];
        sz[x]+=sz[y];
        sz2[x]+=sz2[y];
    } else {
        op[y]=1;
        if (choose[x]==-1){
            if (choose[y]==-1) choose[x]=-1;
            else choose[x]=choose[y]^1;
        }
        sz[x]+=sz[y];
        sz2[x]+=sz[y]-sz2[y];
    }
    //cout<<x<<' '<<y<<' '<<sz[x]<<' '<<sz2[x]<<' '<<choose[x]<<endl;
}
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++) f[i]=s[i]=='1';
    for (int i=1;i<=k;i++){
        int c;scanf("%d",&c);
        for (int j=0;j<c;j++){
            int x;scanf("%d",&x);
            a[x].pb(i);
        }
    }
    for (int i=1;i<=k;i++) pre[i]=i,choose[i]=-1,sz[i]=1,sz2[i]=1;
    for (int i=1;i<=n;i++){
        if (a[i].size()==1){
            int x=a[i][0];
            //cout<<x<<' '<<f[i]<<endl;
            pi tmp=ffind(x);
            ans-=qry(tmp.F);
            choose[tmp.F]=tmp.S^f[i];
            ans+=qry(tmp.F);
        } else if (a[i].size()==2){
            int x=a[i][0],y=a[i][1];
            //cout<<x<<' '<<y<<' '<<f[i]<<endl;
            pi t1=ffind(x);
            pi t2=ffind(y);
            if (t1.F!=t2.F){
                ans-=qry(t1.F);
                ans-=qry(t2.F);
                _union(t1.F,t2.F,t1.S^t2.S^f[i]^1);
                ans+=qry(t1.F);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}