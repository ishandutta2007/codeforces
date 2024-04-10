#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int n,a[mxn],lc,rc,co[mxn];
int cnt[mxn][2];

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d%d%*d",&n,&lc);int ans=0;
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        for(int i=1;i<=lc;++i)++cnt[a[i]][0];
        for(int i=lc+1;i<=n;++i)++cnt[a[i]][1];
        for(int i=1,k;i<=n;++i)k=min(cnt[i][0],cnt[i][1]),cnt[i][0]-=k,cnt[i][1]-=k;
        int c1=0,c0=0;for(int i=1;i<=n;++i)c0+=cnt[i][0]&1,c1+=cnt[i][1]&1,cnt[i][0]-=cnt[i][0]&1,cnt[i][1]-=cnt[i][1]&1;
        int t=min(c1,c0);ans+=t;c1-=t,c0-=t;
        lc=rc=0;
        for(int i=1;i<=n;++i)lc+=cnt[i][0],rc+=cnt[i][1];
        if(c1)c0=c1,swap(lc,rc);
        t=min(rc,c0);
        c0-=t,rc-=t,ans+=t;
        ans+=lc/2+rc/2;
        rc%=2;
        ans+=c0+rc;
        cout<<ans<<endl;
        for(int i=1;i<=n;++i)cnt[i][0]=cnt[i][1]=0;
    }
    return 0;
}