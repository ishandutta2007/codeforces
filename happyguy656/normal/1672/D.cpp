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

const int mxn=2e5+3;
int n,a[mxn],b[mxn];

bool slv(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);for(int i=1;i<=n;++i)scanf("%d",b+i);
    static int cc[mxn];for(int i=1;i<=n;++i)cc[i]=0;
    int p=1;
    for(int i=1;i<=n;++i){
        while(b[p]==b[p+1]&&cc[b[p]])--cc[b[p++]];
        if(a[i]==b[p]){++p;continue;}
        ++cc[a[i]];
    }
    return p>n;
}

int main(){
    int ca;cin>>ca;while(ca--)puts(slv()?"YES":"NO");
    return 0;
}