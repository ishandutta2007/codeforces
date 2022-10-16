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
int n,a[mxn];

bool slv_(){
    scanf("%d",&n);ll S=0;for(int i=1;i<=n;++i)scanf("%d",a+i);
    int p=-1;
    for(int i=1;i<=n;++i){S+=a[i];if(!S)p=i;if(~p&&S)return 0;if(S<0)return 0;}
    return S==0;
}

int main(){
    int ca;cin>>ca;while(ca--)puts(slv_()?"YES":"NO");
    return 0;
}