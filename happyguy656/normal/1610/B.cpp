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
int n,a[mxn],m,b[mxn];
bool ck(int x){
    m=0;for(int i=1;i<=n;++i)if(a[i]!=x)b[++m]=a[i];
    for(int i=1,j=m;i<j;++i,--j)if(b[i]!=b[j])return 0;
    return 1;
}

bool chk(){
    for(int i=1,j=n;i<j;++i,--j)if(a[i]!=a[j])return ck(a[i])||ck(a[j]);
    return 1;
}

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n;for(int i=1;i<=n;++i)scanf("%d",a+i);
        puts(chk()?"yes":"no");
    }
    return 0;
}