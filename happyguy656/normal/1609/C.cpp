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

const int mxn=4e5+3,mxm=1e6+3;
int n,m,a[mxn],b[mxn],nn,p1[mxn],p2[mxn];bool pr[mxm];
int ee(int x){if(x==1)return 0;return pr[x]?1:2;}
int gg(int t,int x,int y){if(!x)return 0;int re=y-x+1;if(x-t==1)--re;return re;}
int main(){
    memset(pr,1,sizeof(pr));for(int i=2;i<mxm;++i)if(pr[i]){for(int j=i*2;j<mxm;j+=i)pr[j]=0;}
    int ca;cin>>ca;while(ca--){
        cin>>n>>m;for(int i=1;i<=n;++i)scanf("%d",a+i);
        ll ans=0;
        for(int t=1;t<=m;++t){
            nn=0;
            for(int i=t;i<=n;i+=m)++nn,b[nn]=b[nn-1]+ee(a[i]);
            for(int i=0;i<=nn;++i)p2[b[i]]=i;
            for(int i=nn;~i;--i)p1[b[i]]=i;
            for(int i=0,x;i<=nn;++i)x=b[i],ans+=gg(i,p1[x+1],p2[x+1]);
            for(int i=0;i<=nn;++i)p1[b[i]]=p2[b[i]]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}