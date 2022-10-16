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
char s[mxn];
int n,b[mxn];

bool slv(){
    scanf("%s",s+1);n=strlen(s+1);if(s[n]=='A')return 0;
    for(int i=1;i<=n;++i)s[i]=s[i]=='A'?1:-1;
    for(int i=1;i<=n;++i)b[i]=b[i-1]+s[i];
    for(int i=1;i<=n;++i)if(b[i]<0)return 0;
    return 1;
}

int main(){
    int ca;cin>>ca;while(ca--)puts(slv()?"YES":"NO");
    return 0;
}