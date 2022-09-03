#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
int f[6005];
int Size[6005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[2005][2005];
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
    }
    if(n%2==0&&m%2==0){
        LL ans=1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(c[i][j]=='?')ans=ans*2%mod;
            }
        }
        printf("%lld\n",ans%mod);
    }
    else if(n%2==0){
        LL ans=0;
        for(int t=0;t<2;t++){
            LL res=1;
            for(int i=0;i<n;i++){
                int tot=0,cnt=0;
                for(int j = 0;j<m;j++){
                    if(c[i][j]=='?')cnt++;
                    if(c[i][j]=='1')tot++;
                }
                if(cnt==0){
                    if((tot&1)!=t)res=0;
                }
                else{
                    for(int j = 1;j<cnt;j++)res=res*2%mod;
                }
            }
            ans+=res;
        }
          printf("%lld\n",ans%mod);
    }
    else if(m%2==0){
        LL ans=0;
        for(int t=0;t<2;t++){
            LL res=1;
            for(int j=0;j<m;j++){
                int tot=0,cnt=0;
                for(int i = 0;i<n;i++){
                    if(c[i][j]=='?')cnt++;
                    if(c[i][j]=='1')tot++;
                }
                if(cnt==0){
                    if((tot&1)!=t)res=0;
                }
                else{
                    for(int j = 1;j<cnt;j++)res=res*2%mod;
                }
            }
            ans+=res;
        }
          printf("%lld\n",ans%mod);
    }
    else{
        LL ans=0;
        for(int t=0;t<2;t++){
            LL res=1;
            LL r[3005],cc[3005];
            MEM(r),MEM(cc);
            for(int i = 0;i<n+m;i++)f[i]=i,Size[i]=0;
            for(int i = 0;i<n;i++){
                for(int j  =0;j<m;j++){
                    if(c[i][j]=='1')r[i]^=1,cc[j]^=1;
                    else if(c[i][j]=='?'){
                        int a=Find(i),b=Find(n+j);
                        if(a!=b)f[a]=b;
                        else res*=2,res%=mod;
                    }
                }
            }
            for(int i = 0;i<n;i++){
                if(r[i]!=t)Size[Find(i)]^=1;
            }
            for(int i = 0;i<m;i++){
                if(cc[i]!=t)Size[Find(i+n)]^=1;
            }
            for(int i = 0;i<n+m;i++){
                if(Size[i])res=0;
            }
            ans+=res;
            ans%=mod;
        }
        printf("%lld\n",ans%mod);
    }
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/