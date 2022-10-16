#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define uu unsigned
#define scanf(x...) assert(~scanf(x))
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){return uniform_int_distribution<>(l,r)(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=2e5+3;
int n,a[mxn],fa[mxn],L[mxn],R[mxn];
ll vl[mxn];

int slv_(){
    scanf("%d",&n);for(int i=2;i<=n;++i)scanf("%d",fa+i);
    for(int i=1;i<=n;++i)scanf("%d%d",L+i,R+i);
    for(int i=0;i<=n;++i)vl[i]=0;
    int re=0;
    for(int i=n;i;--i){
        if(vl[i]>R[i])vl[i]=R[i];
        if(vl[i]<L[i])++re,vl[i]=R[i];
        vl[fa[i]]+=vl[i];
    }
    return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%d\n",slv_());
    return 0;
}