#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=1e6+3;
int n,m,qn,b[mxn],P;
char ss[mxn];
vector<char>s[mxn];
vector<bool>can[mxn];
vector<pii>ve[mxn];
int ans[mxn];
int e(int x,int y){if(x<=0||x>n||y<=0||y>m)return 0;if(can[x][y])return 0;return !can[x-1][y]&&!can[x][y-1];}
void ch(int x,int y){
    b[y]-=e(x+1,y),b[y+1]-=e(x,y+1);
    b[y]-=e(x,y);
    can[x][y]=1;
}
void dfs(int x,int y){
    if(s[x][y]=='X')return;
    if(can[x][y])return;
    ch(x,y);
    if(y!=m)dfs(x,y+1);if(x!=n)dfs(x+1,y);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;++i)s[i].resize(m+3),can[i].resize(m+3);
    for(int i=1;i<=n;++i){
        scanf("%s",ss+1);for(int j=1;j<=m;++j)s[i][j]=ss[j];
    }
    cin>>qn;
    for(int i=1;i<=qn;++i){int l,r;scanf("%d%d",&l,&r);ve[l].emplace_back(r,i);}
    for(int j=1;j<=m;++j)b[j]=n;
    for(int j=m;j;--j)dfs(0,j);
    for(int j=1;j<=m;++j){
        for(int i=n;i;--i)s[i][j-1]='.',dfs(i,j-1);
        P=max(P,j);
        while(P<=m&&!b[P])++P;
        for(auto k:ve[j])ans[k.second]=k.first<P;
    }
    for(int i=1;i<=qn;++i)puts(ans[i]?"yes":"no");
    return 0;
}