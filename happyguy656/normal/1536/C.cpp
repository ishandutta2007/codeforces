#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=5e5+3;
int n;char s[mxn];
int gcd(int a,int b){for(int c;b;c=a%b,a=b,b=c);return a;}
map<pii,int>mp;
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d%s",&n,s+1);
        mp.clear();
        int c1=0,c2=0;
        for(int i=1;i<=n;++i){
            if(s[i]=='D')++c1;else ++c2;
            if(!c1||!c2)printf("%d ",i);else{
                int t=gcd(c1,c2);
                printf("%d ",++mp[pii(c1/t,c2/t)]);
            }
        }
        puts("");
    }
    return 0;
}