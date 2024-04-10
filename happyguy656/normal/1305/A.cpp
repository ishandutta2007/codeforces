#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3;
int n,a[mxn],b[mxn];;

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n;for(int i=1;i<=n;++i)cin>>a[i];for(int i=1;i<=n;++i)cin>>b[i];sort(a+1,a+n+1),sort(b+1,b+n+1);for(int i=1;i<=n;++i)printf("%d ",a[i]);puts("");for(int i=1;i<=n;++i)printf("%d ",b[i]);puts("");
    }
    return 0;
}