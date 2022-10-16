#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
//mt19937 rnd(time(0));
//int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

char s[403][403];
int n,m,z1[403][403],z2[403][403],b[403],sm[403],v1[403],v2[403];

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n>>m;for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)z1[i][j]=s[i][j]=='0',z1[i][j]+=z1[i][j-1];
        for(int j=1;j<=m;++j)for(int i=1;i<=n;++i)z2[i][j]=s[i][j]=='1',z2[i][j]+=z2[i-1][j];
        int ans=2e9;
        for(int l=1;l<=n;++l)for(int r=l+4;r<=n;++r){
            for(int i=1;i<=m;++i)b[i]=z2[r-1][i]-z2[l][i],sm[i]=sm[i-1]+b[i];
            for(int i=1;i<=m;++i)v1[i]=sm[i-1]-b[i]+z1[l][i-1]+z1[r][i-1],v2[i]=-sm[i]-b[i]-z1[l][i]-z1[r][i];
            for(int i=4,mn=2e9;i<=m;++i)mn=min(mn,v2[i-4+1]),ans=min(ans,v1[i]+mn+2*(r-l-1));
        }
        printf("%d\n",ans);
    }
    return 0;
}