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

const int mxn=1e5+3;
int n,m;bool vs[mxn];
void sc(int x){
    for(int i=1;i<=n;++i)if(x!=i)printf("%d %d\n",x,i);
}
int main(){
    int ca;cin>>ca;while(ca--){
        scanf("%d%d",&n,&m);for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),vs[y]=1;
        for(int i=1;i<=n;++i)if(!vs[i]){sc(i);break;}
        for(int i=1;i<=n;++i)vs[i]=0;
    }
    return 0;
}