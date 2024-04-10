#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int n;ll a[mxn],H;
int px[mxn];bool cmp1(int x,int y){return a[x]<a[y];}
bool wk(){
    for(int i=1;i<=n;++i)if(a[i]*2>=H&&a[i]<=H)return printf("1\n%d\n",i),1;
    ll s=0;for(int i=1;i<=n;++i){
        if(s+a[px[i]]<=H)s+=a[px[i]];
        if(s*2>=H){
            printf("%d\n",i);for(int j=1;j<=i;++j)printf("%d ",px[j]);puts("");return 1;
        }
    }
    return 0;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        cin>>n>>H;for(int i=1;i<=n;++i)cin>>a[i],px[i]=i;sort(px+1,px+n+1,cmp1);
        if(!wk())puts("-1");
    }
    return 0;
}