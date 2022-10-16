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

int n,b[111];
int sol(){
    memset(b,0,sizeof(b));
    cin>>n;for(int i=1,x;i<=n;++i)cin>>x,++b[abs(x)];
    int re=0;if(b[0])++re;for(int i=1;i<=100;++i)re+=min(b[i],2);
    return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%d\n",sol());
    return 0;
}