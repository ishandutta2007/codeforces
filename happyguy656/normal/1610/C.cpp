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

const int mxn=2e5+3;
int n,a[mxn],b[mxn];

bool chk(int x){
    int t=0;
    for(int i=1;i<=n;++i){
        if(a[i]>=t&&b[i]>=x-t-1)++t;
    }
    return t>=x;
}

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n;for(int i=1;i<=n;++i)scanf("%d%d",b+i,a+i);
        int l=0,r=n,md;while(l<r){md=(l+r+1)>>1;if(chk(md))l=md;else r=md-1;}
        printf("%d\n",l);
    }
    return 0;
}