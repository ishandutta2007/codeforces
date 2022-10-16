#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd(time(0));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=1e5+3;
int n,a[mxn],b[mxn];
int main(){
    scanf("%d",&n);for(int i=1,x;i<=n;++i)scanf("%d",&x),a[x]=i;
    for(int i=1;i<=n;++i)scanf("%d",b+i),b[i]=a[b[i]];
    int ans=0;
    for(int i=n,mn=1e9;i;--i)ans+=b[i]>mn,mn=min(mn,b[i]);
    printf("%d\n",ans);
    return 0;
}