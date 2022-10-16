#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int c0(ll z){return __builtin_popcountll(z);int re=0;while(z)z-=z&-z,++re;return re;}
ll z1[11][2],U,z2[11][41];
int n,m,b[11][41],dn[11],P=-1;
bool dfs(ll z=0,int d=1){
    if(d==m+1){
        if(P==-2)return 0;
        if(P==-1){bool ok=0;for(int i=0;i<n;++i){int t=z>>i&1;if(ok&&!t)return 0;if(t)ok=1;}return 1;}
        for(int i=0;i<P;++i)if(z>>i&1)return 0;for(int i=P+1;i<n;++i)if(!(z>>i&1))return 0;return 1;
    }
    int k=c0(z1[d-1][0]&z1[d][1]&z);
    for(int i=0;i<=dn[d];++i){
        ll zz=z;
        int t=b[d][0]-i-k;
        zz&=U^z2[d][t];
        zz|=z2[d][t]^z1[d][1];
        if(!dfs(zz,d+1))return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);for(int i=1;i<=m;++i){scanf("%d",&b[i][0]);for(int j=1;j<=b[i][0];++j)scanf("%d",&b[i][j]),--b[i][j];}
    U=(1ll<<n)-1;
    for(int t=1;t<=m;++t){
        z1[t][0]=z1[t-1][0];for(int i=1;i<=b[t][0];++i){
            ll k=1ll<<b[t][i];z1[t][1]|=k;
            z2[t][i]=z2[t][i-1]|k;
        }
        z1[t][0]|=z1[t][1];
        dn[t]=c0(z1[t][0]^z1[t-1][0]);
    }
    for(int i=0;i<n;++i)if(!(z1[m][0]>>i&1)){if(P==-1)P=i;else P=-2;}
    puts(dfs()?"ACCEPTED":"REJECTED");
    return 0;
}