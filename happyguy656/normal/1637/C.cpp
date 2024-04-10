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

const int mxn=1e5+3;
int n,b[mxn];

ll slv(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",b+i);
    ll sm=0;
    for(int i=2;i<n;++i){
        sm+=b[i];sm+=b[i]&1;
    }
    if(n==3&&b[2]%2)return -1;
    for(int i=2;i<n;++i)if(b[i]!=1)return sm>>1;
    return -1;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%lld\n",slv());
    return 0;
}