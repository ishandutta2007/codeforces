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

int n,m;

int main(){
    cin>>n>>m;if(n==1&&m==1)return puts("0"),0;
    if(n==1){for(int i=1;i<=m;++i)printf("%d ",i+1);puts("");return 0;}
    if(m==1){for(int i=1;i<=n;++i)printf("%d\n",i+1);return 0;}
    for(int i=1;i<=n;++i,puts(""))for(int j=n+1;j<=n+m;++j)printf("%d ",i*j);
    return 0;
}