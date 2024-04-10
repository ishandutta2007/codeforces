#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int abc;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,m,a[10004],po[103][103],vs[103],nn,b[103],B,jg[103][2];
bool cmp1(int x,int y){return po[x][B]<po[y][B];}
int main(){
    scanf("%d%d",&n,&m);for(int i=1;i<=n*m;++i)scanf("%d",a+i),po[a[i]][++po[a[i]][0]]=i;
    int L=(n-1)/(m-1)+1;
    for(B=2;B<=m;++B){
        nn=0;for(int i=1;i<=n;++i)if(!vs[i])b[++nn]=i;
        sort(b+1,b+nn+1,cmp1);
        for(int i=1;i<=L&&i<=nn;++i)vs[b[i]]=1,jg[b[i]][0]=po[b[i]][B-1],jg[b[i]][1]=po[b[i]][B];
    }
    for(int i=1;i<=n;++i)printf("%d %d\n",jg[i][0],jg[i][1]);
    return 0;
}