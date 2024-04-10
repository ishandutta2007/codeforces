#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define uu unsigned
int abc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

int n,m,dp[55][1<<10],an;pii fr[55][1<<10];
int db[999],po[11][55][2],be[555];
char s[11][555],re[555],eh[555];
bool vd[55];

int gg(int c1,int z,int c2){
    int zz=0;
    for(int i=0;i<n;++i){
        int p=po[i][c1][z>>i&1];
        if(!po[i][c2][1]){if(po[i][c2][0]<=p)return -1;}
        else if(po[i][c2][1]<=p)return -1;
        else if(po[i][c2][0]<=p)zz|=1<<i;
    }
    return zz;
}

int main(){
    for(int i='a';i<='z';++i)db[i]=++n,eh[n]=i;for(int i='A';i<='Z';++i)db[i]=++n,eh[n]=i;assert(n==52);
    int ca;cin>>ca;while(ca--){
        memset(po,0,sizeof(po));memset(dp,0,sizeof(dp));memset(fr,0,sizeof(fr));
        cin>>n;for(int i=0;i<n;++i)scanf("%s",s[i]+1);for(int i=0;i<n;++i)for(int j=1;s[i][j];++j){
            int c=s[i][j];c=db[c];s[i][j]=c;
            if(!po[i][c][0])po[i][c][0]=j;else po[i][c][1]=j;
        }
        memset(be,0,sizeof(be));
        for(int c=1;c<=52;++c)be[po[0][c][1]]=1;
        memset(vd,1,sizeof(vd));for(int c=1;c<=52;++c)for(int i=0;i<n;++i)if(!po[i][c][0])vd[c]=0;
        int kk=0;
        int p1=0,p2=0;
        for(int c=1;c<=52;++c)dp[c][0]=vd[c],kk+=vd[c];
        if(!kk){puts("0");puts("");continue;}
        for(int t=1;s[0][t];++t){
            int c=s[0][t];
            for(int z=0;z<(1<<n);++z)if(dp[c][z]&&((z&1)==be[t])){
                if(dp[c][z]>dp[p1][p2])p1=c,p2=z;
                for(int cc=1;cc<=52;++cc){
                    int e=gg(c,z,cc);
                    if(~e&&dp[c][z]+1>dp[cc][e])dp[cc][e]=dp[c][z]+1,fr[cc][e]={c,z};
                }
            }
        }
        pii hh;
        an=0;while(dp[p1][p2])hh=fr[p1][p2],re[++an]=eh[p1],p1=hh.first,p2=hh.second;
        re[an+1]=0;
        printf("%d\n",an);reverse(re+1,re+an+1);puts(re+1);
    }
    return 0;
}