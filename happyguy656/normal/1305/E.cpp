#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=5003;
int n,m,a[mxn];

int main(){
    cin>>n>>m;int s=0;for(int t=1;t<=n;++t){
        s+=(t-1)>>1;if(s>=m){
            for(int i=1;i<t;++i)printf("%d ",i);int x=t+2*(s-m);printf("%d ",x);
            int e=x-1;while(e<t||e==1)e+=x;
            for(int i=t+1;i<=n;++i)x+=e,printf("%d ",x);puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}