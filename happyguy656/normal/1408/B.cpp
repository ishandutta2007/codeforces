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

int n,m,a[103];

int cal(){
    n=unique(a+1,a+n+1)-a-1;
    if(m==1)return n==1?1:-1;
    if(m>=n)return 1;
    return (n-2)/(m-1)+1;
}

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n>>m;for(int i=1;i<=n;++i)cin>>a[i];printf("%d\n",cal());
    }
    return 0;
}