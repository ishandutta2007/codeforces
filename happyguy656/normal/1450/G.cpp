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

int n,A,B,b[5003],k1[666],k2[666],k3[666],m,an,oo[666],U;char s[5003];
int ee[1<<20][3];bool dp[1<<20];
bool cmp1(int x,int y){return k1[x]<k1[y];}
bool chk(int z){return 1ll*A*(ee[z][1]-ee[z][0]+1)<=1ll*B*ee[z][2];}
int main(){
    cin>>n>>A>>B>>s+1;n=strlen(s+1);memset(k1,0x3f,sizeof(k1));for(int i=1;i<=n;++i)k1[s[i]]=min(k1[s[i]],i);for(int i=0;i<666;++i)k2[i]=i;sort(k2,k2+666,cmp1);for(int i=0;i<666;++i)k3[k2[i]]=i;
    for(int i=1;i<=n;++i)b[i]=k3[s[i]],m=max(m,b[i]);++m,U=1<<m,--U;
    assert(m<=20);
    for(int i=1,k;i<=n;++i)k=1<<b[i],ee[k][0]=ee[k][1]=i,++ee[k][2];
    for(int i=1,k;i<=n;++i)k=1<<b[i],ee[k][0]=min(ee[k][0],i),ee[k][1]=max(ee[k][1],i);
    ee[0][0]=n;
    for(int z=1,zz;z<=U;++z)zz=z&-z,ee[z][0]=min(ee[zz][0],ee[z^zz][0]),ee[z][1]=max(ee[zz][1],ee[z^zz][1]),ee[z][2]=ee[zz][2]+ee[z^zz][2];
    dp[0]=1;for(int z=0;z<=U;++z){
        int zz=z;while(zz^=zz&-zz,zz)dp[z]|=dp[zz]&&dp[z^zz];
        if(dp[z])for(int i=0;i<m;++i){zz=z|(1<<i);if(chk(zz))dp[zz]=1;}
    }
    for(int i=0;i<m;++i)if(dp[U^(1<<i)])oo[++an]=k2[i];sort(oo+1,oo+an+1);printf("%d\n",an);for(int i=1;i<=an;++i)printf("%c ",oo[i]);puts("");
    return 0;
}