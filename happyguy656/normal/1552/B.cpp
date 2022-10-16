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

const int mxn=5e4+3;
int a[5][mxn],n;
int b[mxn],B;
bool cmp1(int x,int y){return a[B][x]<a[B][y];}
bool win(int x,int y){int c=0;for(int i=0;i<5;++i)c+=a[i][x]<a[i][y];return c>=3;}
int cal(){
    int nw=1;
    for(int i=2;i<=n;++i)if(win(i,nw))nw=i;
    for(int i=1;i<=n;++i)if(i!=nw&&!win(nw,i))return -1;
    return nw;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)for(int j=0;j<5;++j)scanf("%d",&a[j][i]);
        printf("%d\n",cal());
    }
    return 0;
}