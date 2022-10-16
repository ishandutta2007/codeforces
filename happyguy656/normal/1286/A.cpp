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

const int mxn=1e5+3;
int n,a[mxn],b1[mxn],b2[mxn],n1,n2;

int main(){
    cin>>n;for(int i=1;i<=n;++i)cin>>a[i],a[i]=a[i]?(a[i]&1):-1;
    int ans=1e9;
    for(int z=0;z<4;++z){
        a[0]=z&1,a[n+1]=z>>1&1;
        int re=0;
        int c1=n>>1,c2=n>>1;if(n&1)++c1;
        n1=n2=0;
        for(int i=1;i<=n;++i)if(a[i]==1)--c1;
        for(int i=1;i<=n;++i)if(a[i]==0)--c2;
        for(int i=0;i<=n;++i)if(~a[i]){
            int l=i;while(a[i+1]==-1)++i;int r=i;
            if(l==r)re+=a[i]^a[i+1];else{
                ++r;
                if(a[l]^a[r])++re;
                else{
                    re+=2;
                    if(a[l])b1[++n1]=r-l-1;
                    else b2[++n2]=r-l-1;
                }
            }
        }
        sort(b1+1,b1+n1+1),sort(b2+1,b2+n2+1);
        for(int i=1;i<=n1;++i)if(c1>=b1[i])c1-=b1[i],re-=2;
        for(int i=1;i<=n2;++i)if(c2>=b2[i])c2-=b2[i],re-=2;
        ans=min(ans,re);
    }
    printf("%d\n",ans);
    return 0;
}