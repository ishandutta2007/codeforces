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

const int mxn=1e5+3;
int n,a[mxn];
bool chk(int i,int j,int k){
    if(k==i||k==j)return 0;
    return (a[k]-a[i])*(k-j)!=(a[k]-a[j])*(k-i);
}
int sol(){
    cin>>n;for(int i=1;i<=n;++i)scanf("%d",a+i);
    if(n<=2)return 0;
    int re=n;
    for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j){
        int c=0;for(int k=1;k<=n;++k)c+=chk(i,j,k);
        re=min(re,c);
    }
    return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%d\n",sol());
    return 0;
}