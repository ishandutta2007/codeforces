#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

bool mp[555][555];
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        int x,y;scanf("%d%d",&x,&y);
        memset(mp,0,sizeof(mp));
        mp[1][1]=mp[1][y]=mp[x][1]=mp[x][y]=1;
        for(int j=3;j<y-1;j+=2)mp[1][j]=mp[x][j]=1;
        for(int i=3;i<x-1;i+=2)mp[i][1]=mp[i][y]=1;
        for(int i=1;i<=x;++i,puts(""))for(int j=1;j<=y;++j)putchar(mp[i][j]?'1':'0');
    }
    return 0;
}