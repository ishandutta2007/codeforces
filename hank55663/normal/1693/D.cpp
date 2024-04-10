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
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
#define MXN 1000000
int p[200005];
map<pii,int> dp[200005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&p[i]);
    }
    dp[0][mp(0,n+1)]++;
    p[n]=n+1;
    long long ans=0;
    for(int i = 0;i<n;i++){
        dp[i+1][mp(0,n+1)]++;
        for(auto pp:dp[i]){
            pair<pii,int> it=pp;

            if(it.x.x<it.x.y){
                if(p[i]>it.x.y){
                    it.x.x=p[i];
                }
                else if(p[i]<it.x.x){
                    it.x.y=p[i];
                }
                else if(p[i+1]>p[i]){
                    it.x.x=p[i];
                }
                else{
                    it.x.y=p[i];
                }
                            ans+=it.y;
                dp[i+1][it.x]+=it.y;
            }   
            else{
                if(p[i]>it.x.x)it.x.x=p[i];
                else if(p[i]<it.x.y)it.x.y=p[i];
                else continue;
                            ans+=it.y;
                dp[i+1][it.x]+=it.y;
            }   
       //     printf("%d %d %d %d\n",i,pp.x.x,pp.x.y,pp.y);
        }
    }
    //dc(0,n-1);
    printf("%lld\n",ans);
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}