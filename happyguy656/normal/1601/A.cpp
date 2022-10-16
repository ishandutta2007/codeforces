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

const int mxn=2e5+3;
int gcd(int x,int y){for(int z;y;z=x%y,x=y,y=z);return x;}
int n,b[mxn];

int main(){
    int ca;cin>>ca;while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",b+i);
        int k=0;for(int i=0;i<30;++i){int c=0;for(int j=1;j<=n;++j)c+=b[j]>>i&1;k=gcd(k,c);}
        for(int i=1;i<=n;++i)if(k%i==0)printf("%d ",i);puts("");
    }
    return 0;
}