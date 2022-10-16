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
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=1e5+3;
int n,m,an;ll v[mxn],ans[mxn][3];
VI v1,v2;
int main(){
    cin>>n>>m;while(m--){int x,y,z;scanf("%d%d%d",&x,&y,&z);v[x]+=z,v[y]-=z;}
    for(int i=1;i<=n;++i)if(v[i]>0)v1.push_back(i);
    for(int i=1;i<=n;++i)if(v[i]<0)v2.push_back(i);
    while(v1.size()&&v2.size()){
        int x=*--v1.end(),y=*--v2.end();ll z=min(v[x],-v[y]);
        v[x]-=z,v[y]+=z;ans[++an][0]=x,ans[an][1]=y,ans[an][2]=z;
        if(!v[x])v1.pop_back();if(!v[y])v2.pop_back();
    }
    printf("%d\n",an);for(int i=1;i<=an;++i)printf("%lld %lld %lld\n",ans[i][0],ans[i][1],ans[i][2]);
    return 0;
}