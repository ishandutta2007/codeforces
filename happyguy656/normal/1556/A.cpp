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

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        int x,y;scanf("%d%d",&x,&y);
        if((x-y)&1)puts("-1");else if(x==0&&y==0)puts("0");else if(x==y)puts("1");else puts("2");
    }
    return 0;
}