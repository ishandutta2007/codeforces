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

int n,a[103],b[103],c[103],d[103];

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n;for(int i=1;i<=n;++i)cin>>a[i];for(int i=1;i<=n;++i)cin>>b[i];for(int i=1;i<=n;++i)cin>>c[i];
        d[1]=a[1];for(int i=2;i<n;++i)if(a[i]!=d[i-1])d[i]=a[i];else d[i]=b[i];
        if(a[n]!=d[n-1]&&a[n]!=d[1])d[n]=a[n];
        if(b[n]!=d[n-1]&&b[n]!=d[1])d[n]=b[n];
        if(c[n]!=d[n-1]&&c[n]!=d[1])d[n]=c[n];
        for(int i=1;i<=n;++i)printf("%d ",d[i]);puts("");
    }
    return 0;
}