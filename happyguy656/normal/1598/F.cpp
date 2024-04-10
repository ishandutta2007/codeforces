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

const int mxn=4e5+3;
int n;char s[mxn];int po[mxn],le[mxn];
int dp[1<<20],U,hh[20],sm[1<<20],ans,ls[mxn];
VI p1[20],p2[20],qz[20];

int main(){
    scanf("%d",&n);for(int i=0,p=1;i<n;++i)po[i]=p,scanf("%s",s+p),le[i]=strlen(s+p),p+=le[i];
    po[n]=po[n-1]+le[n-1];U=1<<n;--U;
    for(int t=0;t<n;++t){
        memset(ls,0,sizeof(ls));
        p1[t].resize(le[t]+1),p2[t].resize(le[t]+1),qz[t].resize(le[t]+1);
        int v=0,mn=0;for(int i=po[t];i<po[t+1];++i)v+=s[i]=='('?1:-1,mn=min(mn,v);
        sm[1<<t]=v;
        hh[t]=-mn;
        v=-mn;
        for(int i=po[t],j=1;i<po[t+1];++i,++j){
            v+=s[i]=='('?1:-1;if(!p1[t][v])p1[t][v]=j;p2[t][v]=j;
            qz[t][j]=qz[t][ls[v]]+1,ls[v]=j;
        }
    }
    for(int z=1,zz;z<=U;++z)zz=z&-z,sm[z]=sm[zz]+sm[z^zz];
    memset(dp,0xc0,sizeof(dp));dp[0]=0;
    for(int z=0;z<=U;++z)if(sm[z]>=0){
        for(int i=0;i<n;++i)if(!(z>>i&1)){
            int k=hh[i]-sm[z]-1;
            if(k>=0&&p1[i][k])ans=max(ans,dp[z]+qz[i][p1[i][k]-1]);
            else{
                ++k;k=k<0?0:p2[i][k];
                dp[z|(1<<i)]=max(dp[z|(1<<i)],dp[z]+qz[i][k]);
            }
        }
    }
    printf("%d\n",max(ans,dp[U]));
    return 0;
}