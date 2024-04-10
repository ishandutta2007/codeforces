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

const int mxn=3e4+9;
int n,m,a[mxn],qn,ln;
ll nm[mxn][5][5][2],ju[16][mxn][5][2];
ll C(int x,int y){if(x==-1)return y==0;if(x<0||y<0)return 0;if(y==0)return 1;if(y==1)return x;if(y==2)return x*(x-1ll)/2;if(y==3)return x*(x-1ll)*(x-2)/6;return x*(x-1ll)*(x-2)*(x-3)/24;}
bool cmp1(int x,int y){return a[x]<a[y];}
int ask(int x,ll y){
    ll HA=0;for(int i=0;i<=m;++i)HA+=C(n-1,i);if(HA<y)return -1;
    int p=1,cc=m;
    static int wz[9][2];int nn=0;
    while(p<n){
        for(int k=ln;~k;--k)if(y>ju[k][p][cc][0]&&y<=ju[k][p][cc][1])y-=ju[k][p][cc][0],p+=1<<k;
        if(p==n+1)break;
        wz[++nn][0]=p;int p0=p;
        if(y>nm[p][0][cc][0]&&y<=nm[p][0][cc][1])assert(0);assert(p<n);
        for(int k=1;k<=m;++k)if(y>nm[p][k][cc][0]&&y<=nm[p][k][cc][1]){y-=nm[p][k][cc][0],p+=k,cc-=k;break;}
        assert(p<=n);
        if(p0<n)assert(p>p0);
        wz[nn][1]=p;
        ++p;
//        assert(wz[nn][0]>=n||wz[nn][0]<wz[nn][1]);
    }
    for(int i=1;i<=nn;++i)if(x<wz[i][0])return a[x];else if(x<=wz[i][1])return a[wz[i][0]+wz[i][1]-x];
    return a[x];
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d%d%d",&n,&m,&qn);for(int i=1;i<=n;++i)scanf("%d",a+i);ln=log(n)/log(2)+0.1;
        for(int i=1;i<=n;++i){
            static int oo[7];for(int k=0;k<=m;++k)oo[k]=i+k;
            sort(oo,oo+m+1,cmp1);
            for(int t=0;t<=m;++t){
                int x=oo[t]-i;
                for(int ii=0;ii<=m;++ii)nm[i][x][ii][1]=C(n-i-x-1,ii-x);
                for(int ii=1;ii<=m;++ii)nm[i][x][ii][1]+=nm[i][x][ii-1][1];
                for(int ii=0;ii<=m;++ii)nm[i][x][ii][0]=t?nm[i][oo[t-1]-i][ii][1]:0;
                for(int ii=0;ii<=m;++ii)nm[i][x][ii][1]+=nm[i][x][ii][0];
            }
        }
//        puts("..");
        memset(ju,0,sizeof(ju));
        for(int i=1;i<=n;++i)for(int j=0;j<=m;++j)ju[0][i][j][0]=nm[i][0][j][0],ju[0][i][j][1]=nm[i][0][j][1];
        for(int k=1;k<=ln;++k)for(int i=1;i+(1<<k)<=n+1;++i)for(int j=0;j<=m;++j){
            ll t=ju[k-1][i][j][0];int t2=1<<(k-1);
            ju[k][i][j][0]=ju[k-1][i+t2][j][0]+t;
            ju[k][i][j][1]=min(ju[k-1][i][j][1],ju[k-1][i+t2][j][1]+t);
        }
 //       puts("...");
        while(qn--){
            int x;ll y;scanf("%d%lld",&x,&y);
            printf("%d\n",ask(x,y));
        }
    }
    
    return 0;
}