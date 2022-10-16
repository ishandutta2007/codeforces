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
int n,a[mxn],B[mxn],px[mxn],b[mxn],mx[mxn];
bool ok[mxn];
bool cmp1(int x,int y){return a[x]<a[y];}

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n;for(int i=1;i<=n;++i)scanf("%d",a+i);for(int i=1;i<=n;++i)scanf("%d",B+i);
        for(int i=1;i<=n;++i)px[i]=i;sort(px+1,px+n+1,cmp1);
        for(int i=1;i<=n;++i)b[i]=B[px[i]];
        for(int i=1;i<=n;++i)mx[i]=max(mx[i-1],b[i]);
        for(int i=1;i<=n;++i)ok[i]=0;
        int p=n-1,v=b[n];
        while(p&&mx[p]>v)v=min(v,b[p--]);
        for(int i=p+1;i<=n;++i)ok[px[i]]=1;
        for(int i=1;i<=n;++i)printf("%d",ok[i]);puts("");
    }
    return 0;
}