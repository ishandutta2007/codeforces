#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cout<<(k>>20)<<endl;}

const int mxn=1e6+3,mod=1e9+7;

int n,ha[mxn],b[mxn],ah[mxn],tj[mxn],bg[mxn];
bool ip[mxn];
void init(){
    static int pr[mxn],pt,mp[mxn],mv[mxn];
    ha[1]=mp[1]=1;for(int i=2;i<=n;++i){
        if(!mv[i]){mv[i]=i,pr[++pt]=i,ip[i]=1;int t=n/i;if(!mp[t])mp[t]=i;ha[i]=mp[t],ah[i]=i;}
        for(int j=1;j<=pt&&pr[j]<=mv[i]&&i*pr[j]<=n;++j){
            int x=i*pr[j];mv[x]=pr[j];if(pr[j]==mv[i])ha[x]=ha[i],ah[x]=ah[i];else ha[x]=ha[i]*ha[pr[j]],ah[x]=ah[i]*pr[j];
        }
    }
    for(int i=1;i<=n;++i)if(ip[i]&&1ll*i*i>n)for(int x=i;x<=n;x+=i)bg[x]=i;
}
int slv(){
    cin>>n;init();for(int i=1;i<=n;++i)scanf("%d",b+i);
    static bool vs[mxn];
    for(int i=n;i;--i){
        int x=b[i];if(!x)continue;if(ha[x]!=ha[i])return 0;
        x=bg[x];if(1ll*x*x>n){if(b[bg[i]]&&b[bg[i]]!=x)return 0;b[bg[i]]=x;}
    }
    for(int i=1;i<=n;++i)if(b[i]&&vs[b[i]])return 0;else vs[b[i]]=1;
    ll re=1;
    int c=0;for(int i=1;i<=n;++i)if(ha[i]==1&&!vs[i])vs[i]=1,re*=++c,re%=mod;
    memset(tj,0,sizeof(tj));
    for(int i=1;i<=n;++i)if(!vs[i]&&ip[i]&&1ll*i*i>n)vs[i]=1,re*=++tj[n/i],re%=mod;
    memset(tj,0,sizeof(tj));
    for(int i=1;i<=n;++i)if(!vs[i])re*=++tj[ah[i]],re%=mod;
    return re;
}
int main(){
    printf("%d\n",slv());
    return 0;
}