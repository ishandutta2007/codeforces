#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a13=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a13;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}
bool can(int x,int y,int z){
    if(y==1)return (x-1)%z==0;
    for(ll t=1;t<=x;t*=y)if((x-t)%z==0)return 1;
    return 0;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        puts(can(x,y,z)?"Yes":"No");
    }
    return 0;
}