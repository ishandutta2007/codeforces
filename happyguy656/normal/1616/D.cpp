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

const int mxn=1e5+3;
int n,a[mxn],po[mxn],px[mxn],tk[mxn],tn;ll b[mxn];
bool cmp1(int x,int y){return b[x]<b[y];}
set<int>st;
int sol(){
    cin>>n;for(int i=1;i<=n;++i)scanf("%d",a+i);
    int X;cin>>X;for(int i=1;i<=n;++i)a[i]-=X;
    for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
    for(int i=0;i<=n;++i)px[i]=i;sort(px,px+n+1,cmp1);
    st.clear();st.insert(n+5);
    for(int i=0,p=0;i<=n;++i){
        int t=px[i];
        while(b[t]>b[px[p]])st.insert(px[p++]);
        po[t]=*st.lower_bound(t+2);
    }
    tn=0;for(int i=0;i<=n;++i)if(po[i]<=n){
        while(tn&&po[i]<=po[tk[tn]])--tn;tk[++tn]=i;
    }
    int re=0;
    for(int i=1,p=0;i<=tn;++i)if(p<=tk[i]){
        p=po[tk[i]],++re;
    }
    return n-re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%d\n",sol());
    return 0;
}