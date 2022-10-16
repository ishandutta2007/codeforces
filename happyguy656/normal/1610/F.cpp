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
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cout<<(k>>20)<<endl;}

const int mxn=6e5+5,mxm=mxn*4;
int n,m,d1[mxn],d2[mxn],gn=1,D,tk[mxn],tn;
int to[mxm],nxt[mxm],fir[mxn],cur[mxn],vs[mxm];void gad(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn,to[++gn]=x,nxt[gn]=fir[y],fir[y]=gn;}

void eul(int s){
    to[0]=s;tk[++tn]=0;
    while(tn){
        int x=to[tk[tn]];
        int&e=cur[x];while(~e&&vs[e>>1])e=nxt[e];
        if(~e)tk[++tn]=e,vs[e>>1]=(e&1)+1;else --tn;
    }
}

int main(){
    memset(fir,-1,sizeof(fir));
    cin>>n>>m;for(int i=1,x,y,z;i<=m;++i){scanf("%d%d%d",&x,&y,&z);if(z==1)gad(x,y),d1[x]^=1,d1[y]^=1;else gad(x+n,y+n),d2[x]^=1,d2[y]^=1;}
    D=2*n+1;for(int i=1;i<=n;++i)if(d1[i]&&d2[i])gad(i,i+n);else if(d1[i])gad(i,D);else if(d2[i])gad(i+n,D);
    for(int i=1;i<=D;++i)cur[i]=fir[i];
    for(int i=1;i<=D;++i)if(~cur[i])eul(i);
    int ee=0;for(int i=1;i<=n;++i)ee+=d1[i];printf("%d\n",ee);
    for(int i=1;i<=m;++i)printf("%d",vs[i]);puts("");
    return 0;
}