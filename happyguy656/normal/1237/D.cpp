#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd(time(0));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e5+3;
int n,a[mxn],tk[mxn],tn;
int px[mxn],nx[mxn],da[mxn];
bool cmp1(int x,int y){return a[x]<a[y];}
set<int>st;
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),a[n+i]=a[i];
    for(int i=1;i<=2*n;++i)px[i]=i;sort(px+1,px+2*n+1,cmp1);
    for(int i=2*n;i;--i){while(tn&&a[i]>=a[tk[tn]])--tn;if(i<=n)nx[i]=tk[tn];tk[++tn]=i;}
    for(int i=1;i<=2*n;++i)if(!nx[i])nx[i]=2*n+1;
    for(int t=1,p=0;t<=2*n;++t){
        int x=px[t];if(x>n)continue;while(p!=2*n&&a[px[p+1]]<=(a[x]-1)/2)st.insert(px[++p]);
        auto it=st.lower_bound(x);if(it!=st.end()&&*it<nx[x])da[x]=*it-x;
    }
    for(int i=1;i<=n;++i)da[n+i]=da[i];
    for(int t=2*n,x;t;--t){x=px[t];if(!da[x]&&x<=n)da[x]=da[x+n]=(da[nx[x]]?da[nx[x]]:666666)+nx[x]-x;}
//    for(int i=n;i;--i)if(!da[i])da[i]=da[nx[i]]+nx[i]-i;
    for(int i=1;i<=n;++i)printf("%d ",da[i]>2*n?-1:da[i]);puts("");
    return 0;
}