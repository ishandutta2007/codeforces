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
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=1e5+3;
int n,a[mxn];

bool slv(){
    cin>>n;for(int i=1;i<=n;++i)cin>>a[i];
    int sm=0;for(int i=1;i<=n;++i)sm+=a[i]-1;
    return sm&1;
}

int main(){
    int ca;cin>>ca;while(ca--)puts(slv()?"errorgorn":"maomao90");
    return 0;
}