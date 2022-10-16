#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=5e5+3;
int n,a[mxn],Q,ans[mxn];
vector<pii>ak[mxn];
pii b[mxn];

inline void ins(pii x){
    for(int i=25;~i;--i)if(x.first>>i&1){
        if(x.second>b[i].second)swap(x,b[i]);
        x.first^=b[i].first;
    }
}
inline int ask(int t){
    int res=0;
    for(int i=25;~i;--i)if(!(res>>i&1)&&b[i].second>=t)res^=b[i].first;
    return res;
}

int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
    scanf("%d",&Q);for(int i=1,x,y;i<=Q;++i)scanf("%d%d",&x,&y),ak[y].push_back(pii(x,i));
    for(int i=1;i<=n;++i){
        ins(pii(a[i],i));
        for(auto j:ak[i])ans[j.second]=ask(j.first);
    }
    for(int i=1;i<=Q;++i)printf("%d\n",ans[i]);
    return 0;
}