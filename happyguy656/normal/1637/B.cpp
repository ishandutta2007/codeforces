#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf(x...) assert(scanf(x))
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=1e4+3;
int n,b[mxn],v1[mxn],v2[mxn];

ll slv(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",b+i);
    ll re=0;for(int i=1;i<=n;++i){re+=i*(n-i+1);if(!b[i])re+=i*(n-i+1);}
    return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%lld\n",slv());
    return 0;
}