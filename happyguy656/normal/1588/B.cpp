#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define uu unsigned
int abc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

int n;

ll ask(int l,int r){printf("? %d %d\n",l,r);fflush(stdout);ll x;scanf("%lld",&x);return x;}

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n;
        ll nm=ask(1,n);
        int l=1,r=n,md;while(l!=r){md=(l+r)>>1;if(ask(1,md)==nm)r=md;else l=md+1;}
        int k=l,y=nm-ask(1,k-1)+1;
        ll z=nm-1ll*y*(y-1)/2;
        l=1,r=n,md;while(l!=r){md=(l+r)>>1;if(1ll*md*(md-1)/2>=z)r=md;else l=md+1;}
        printf("! %d %d %d\n",k-y+1-l,k-y+1,k);
        fflush(stdout);
    }
    return 0;
}