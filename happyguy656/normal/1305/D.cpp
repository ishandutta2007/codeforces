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
typedef vector<int>VI;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1003;
VI g[mxn];int n,le,vs[mxn],dg[mxn];
void era(int x){for(int y:g[x])--dg[y];vs[x]=1;--le;}
int ask(int x,int y){printf("? %d %d\n",x,y);fflush(stdout);cin>>x;return x;}
void dfs(int x,int f){
    era(x);for(int y:g[x])if(y!=f&&!vs[y])dfs(y,x);
}
int main(){
    cin>>n;for(int i=1,x,y;i<n;++i)cin>>x>>y,g[x].push_back(y),g[y].push_back(x),++dg[x],++dg[y];le=n;
    while(le>1){
        int x=-1,y=-1,h=-1;
        for(int i=1;i<=n;++i)if(!vs[i]&&dg[i]>1){
            h=i;
            for(int z:g[i])if(!vs[z]){
                if(x==-1)x=z;else if(y==-1)y=z;
            }
            break;
        }
        if(~x){
            int z=ask(x,y);
            if(z==x||z==y)dfs(h,z);else dfs(x,h),dfs(y,h);
        }else{
            assert(le==2);
            for(int i=1;i<=n;++i)if(!vs[i]){if(x==-1)x=i;else y=i;}
            printf("! %d\n",ask(x,y));return 0;
        }
    }
    for(int i=1;i<=n;++i)if(!vs[i])printf("! %d\n",i);
    return 0;
}