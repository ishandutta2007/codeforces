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

const int mxn=2e5+3;
int n,b[mxn];

int slv(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",b+i);
    int c=0;for(int i=1;i<n;++i)c+=b[i]==b[i+1];if(c<=1)return 0;
    int v1=1e9,v2=0;for(int i=1;i<n;++i)if(b[i]==b[i+1])v1=min(v1,i),v2=max(v2,i);
    return max(v2-v1-1,1);
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%d\n",slv());
    return 0;
}