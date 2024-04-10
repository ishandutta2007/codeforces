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
//mt19937 rnd(time(0));
//int rd(int l,int r){return rnd()%(r-l+1)+l;}

const int mxn=1e5+3;
int n,m,a[mxn],b[mxn];
bool chk(){
    ll s=0;for(int i=1;i<=m;++i)s+=a[i];if(s<n)return 0;
    for(int i=1;i<=m;++i)if(a[i]+i-1>n)return 0;
    b[m+1]=n+1;
    for(int i=m;i;--i){
        b[i]=max(b[i+1]-a[i],i);
    }
    for(int i=1;i<=m;++i)printf("%d ",b[i]);puts("");
    return 1;
}
int main(){
    cin>>n>>m;for(int i=1;i<=m;++i)cin>>a[i];
    if(!chk())puts("-1");
    return 0;
}