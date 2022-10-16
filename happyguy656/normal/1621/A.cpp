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

void slv(){
    int n,m;cin>>n>>m;
    int c=0;for(int i=1;i<=n;i+=2)++c;
    if(m>c)return puts("-1"),void();
    for(int i=1;i<=n;++i,puts(""))for(int j=1;j<=n;++j)putchar(i==j&&i<=2*m-1&&i%2?'R':'.');
}

int main(){
    int ca;cin>>ca;while(ca--)slv();
    return 0;
}