#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=4e5+3;
int ans[mxn],an;
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        int x,y;scanf("%d%d",&x,&y);int n=x+y;an=0;
        int m=(n+1)>>1;
        for(int i=0;i<=x&&i<=m;++i)if(x-i<=n-m)ans[++an]=x-i+m-i;
        swap(x,y);
        for(int i=0;i<=x&&i<=m;++i)if(x-i<=n-m)ans[++an]=x-i+m-i;
        sort(ans+1,ans+an+1),an=unique(ans+1,ans+an+1)-ans-1;
        printf("%d\n",an);
        for(int i=1;i<=an;++i)printf("%d ",ans[i]);puts("");
    }
    return 0;
}