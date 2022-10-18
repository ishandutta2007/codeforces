#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,ll>pii;
typedef vector<int>VI;
mt19937 rnd(6);//(ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e5+3;
int n,b[mxn],a[mxn],an,ans[mxn];
void cz(int x){ans[++an]=x-1;int h=b[x-1]^b[x]^b[x+1];b[x-1]=b[x]=b[x+1]=h;}
void wk1(int x){
    for(int i=x-1;i;--i)if(b[i]){
        if(b[i-1])cz(i);else{
            cz(i-1);if(b[i])cz(i);
        }
    }
}
void wk2(int x){
    for(int i=x+1;i<=n;++i)if(b[i]){
        if(b[i+1])cz(i);else{
            cz(i+1);if(b[i])cz(i);
        }
    }
}
bool chk(){
    for(int i=1;i<=n;++i)a[i]=a[i-1]^b[i];
    if(a[n])return 0;
    for(int i=1;i<=n;++i)if(!a[i-1]&&!b[i])return wk1(i),wk2(i),1;
    for(int i=1;i<=n;++i)if(!b[i]){
        int l=i,t=1;
        while(i!=n&&!b[i+1])++i,t^=1;
        if(t){
            for(int j=l;j!=i;j+=2)cz(j);
            cz(i);wk1(i-1),wk2(i+1);
            return 1;
        }
    }
    return 0;
}

int main(){
    int ca;cin>>ca;while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",b+i);an=0;
        if(!chk())puts("NO");else{puts("YES");printf("%d\n",an);for(int i=1;i<=an;++i)printf("%d ",ans[i]);puts("");}
    }
    return 0;
}