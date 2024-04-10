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

const int mxn=1003;
int n,m,a[1003][1003],b[1003][1003],C,be[1003];
void sol(int x){
    if(x<=m){
        C=1;for(int i=1;i<=x;++i)for(int j=i+1;j<=x;++j)a[i][j]=1;return;
    }
    VI be;be.resize(x+1);
    int nn=1;
    for(int i=1,p=m;i<=x;++i){
        if(i>p)++nn,p+=m;
        be[i]=nn;
    }
    sol(nn);
    ++C;
    for(int i=1;i<=x;++i)for(int j=i+1;j<=x;++j)if(be[i]==be[j])b[i][j]=C;else b[i][j]=a[be[i]][be[j]];
    for(int i=1;i<=x;++i)for(int j=i+1;j<=x;++j)a[i][j]=b[i][j];
}

int main(){
    cin>>n>>m;sol(n);
    printf("%d\n",C);for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)printf("%d ",a[i][j]);puts("");
    return 0;
}