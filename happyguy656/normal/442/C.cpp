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
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cout<<(k>>20)<<endl;}

const int mxn=5e5+3;
int n,a[mxn],px[mxn],L,R;bool vs[mxn];
ll ans=0;int c1;
bool cmp1(int x,int y){return a[x]<a[y];}
void add(int x){
    vs[x]=1;
    if(x<L)L=x,c1+=!vs[x+1];else if(x>R)R=x,c1+=!vs[x-1];else --c1,c1+=!vs[x-1],c1+=!vs[x+1];
}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<=n;++i)px[i]=i;sort(px+1,px+n+1,cmp1);
    for(int t=n;t;--t){
        int x=px[t];if(t==n)vs[x]=1,L=R=x;
        else add(x),ans+=1ll*(n-t-1+c1)*(a[px[t]]-a[px[t-1]]);
    }
    cout<<ans<<endl;
    return 0;
}