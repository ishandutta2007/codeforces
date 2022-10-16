#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define uu unsigned
int abc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=1e5+3;
int n,a[mxn];

bool chk(){
    scanf("%d",&n);
    bool ok=1;
    for(int i=1,x;i<=n;++i){scanf("%d",&x);int k=i;while(ok&&k&&x%(k+1)==0)--k;if(!k)ok=0;}
    return ok;
}

int main(){
    int ca;cin>>ca;while(ca--)puts(chk()?"yes":"no");
    return 0;
}