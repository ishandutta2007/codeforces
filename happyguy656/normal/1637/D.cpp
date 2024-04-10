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
int n,a[mxn],b[mxn];
bitset<10001>bt;
ll slv(){
    int S=0,s2=0;
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),S+=a[i],s2+=a[i]*a[i];for(int i=1;i<=n;++i)scanf("%d",b+i),S+=b[i],s2+=b[i]*b[i];
    bt.reset();bt[0]=1;for(int i=1;i<=n;++i)bt=(bt<<a[i])|(bt<<b[i]);
    for(int i=S>>1;~i;--i)if(bt[i]){
        return i*i+(S-i)*(S-i)+(n-2)*s2;
    }
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%lld\n",slv());
    return 0;
}