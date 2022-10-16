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
mt19937 rnd(time(0));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e4+3;
int n,a[mxn],s=0;

int main(){
    scanf("%d",&n);for(int i=1,e=1;i<=n;++i){int x;scanf("%d",&x);int y=x>>1;if(x%2)e^=1,y+=e;printf("%d\n",y);}
    
    return 0;
}