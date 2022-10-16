#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e5+3;
int n,qn,a[mxn],re[mxn];ll ans;
map<pii,int>mp;
void add(int x,int y){ans-=max(re[x],0),re[x]+=y,ans+=max(re[x],0);}
int main(){
    cin>>n;for(int i=1;i<=n;++i)scanf("%d",a+i),re[i]=a[i],ans+=a[i];cin>>qn;while(qn--){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        int k=mp[pii(x,y)];if(k)add(k,1),mp[pii(x,y)]=z;
        if(z)mp[pii(x,y)]=z,add(z,-1);
        printf("%lld\n",ans);
    }
    return 0;
}