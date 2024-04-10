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

int ask(int x){printf("? %d\n",x);fflush(stdout);scanf("%d",&x);return x;}

int main(){
    a[1]=5,a[2]=2,a[3]=7,a[4]=3,a[5]=5,a[6]=6;
    cin>>n;int l=1,r=5e6,md;while(l!=r){md=(l+r)>>1;if(ask(md)==1)r=md;else l=md+1;}
    ll da=r;
    for(int i=2;i<=n;++i){
        ll x=ask(r/i);
        if(x)da=min(da,r/i*x);
    }
    printf("! %lld\n",da);
    return 0;
}