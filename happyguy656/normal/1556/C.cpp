#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int abc;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1003;
int n,a[mxn];

int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
    ll ans=0;
    for(int l=1;l<=n;l+=2){
        ll s=0,mn=a[l]-1;for(int r=l;r<=n;++r){
            if(r%2==0){
                ll x=max(s-a[r],0ll),y=min(s-1,mn);
                if(x<=y)ans+=y-x+1;
                s-=a[r];
            }else s+=a[r];
            mn=min(mn,s);if(s<0)break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}