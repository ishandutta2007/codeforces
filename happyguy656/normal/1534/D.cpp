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

const int mxn=2003;
int n,g[mxn][mxn],b[mxn],de[mxn],fa[mxn];
void aak(int x){printf("? %d\n",x);fflush(stdout);for(int i=1;i<=n;++i)scanf("%d",b+i);}
vector<int>dd[mxn];
int main(){
    scanf("%d",&n);
    aak(1);for(int i=1;i<=n;++i)de[i]=b[i],dd[b[i]].push_back(i);
    for(int i:dd[1])fa[i]=1;
    
    for(int d=2;d<=n;++d){
        for(int i:dd[d])if(!fa[i]){
            aak(i);
            for(int j=1;j<=n;++j)if(b[j]==1){if(de[j]==de[i]+1)fa[j]=i;else fa[i]=j;}
            for(int j=1;j<=n;++j)if(b[j]==2&&de[j]==de[i])fa[j]=fa[i];
        }
    }
    puts("!");
    for(int i=2;i<=n;++i)printf("%d %d\n",fa[i],i),assert(fa[i]);
    return 0;
}