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
const int mxn=1111;
int a[mxn],n;
set<int>s1,s2;
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
        while(n<=300){
            bool fl=0;s1.clear(),s2.clear();
            for(int i=1;i<=n;++i)s1.insert(a[i]);
            for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(!s1.count(abs(a[i]-a[j])))s2.insert(abs(a[i]-a[j]));
            if(!s2.size()) break;
            if(s1.size()+s2.size()>300){n=301;break;}
            n=0;for(int i:s1)a[++n]=i;for(int i:s2)a[++n]=i;
        }
        if(n>300)puts("No");else{puts("Yes");printf("%d\n",n);for(int i=1;i<=n;++i)printf("%d ",a[i]);puts("");}
    }
    return 0;
}