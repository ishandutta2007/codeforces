#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define uu unsigned
#define scanf(x...) assert(~scanf(x))
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){return uniform_int_distribution<>(l,r)(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=2e5+5;
VI g[mxn];int n,m,vl[mxn],nm[mxn];
VI ve[mxn];

int main(){
    cin>>n>>m;for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),g[y].push_back(x),++nm[x];
    memset(vl,0x3f,sizeof(vl));ve[0].push_back(n);vl[n]=0;for(int t=0;t<=m+2;++t){
        for(int x:ve[t])if(vl[x]==t){
            for(int y:g[x]){
                int v=vl[x];v+=nm[y]--;
                if(v<vl[y])vl[y]=v,ve[v].push_back(y);
            }
        }
    }
    cout<<vl[1]<<endl;
    return 0;
}