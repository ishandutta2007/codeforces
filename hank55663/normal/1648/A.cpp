#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
#define MXN 2005
vector<int> vx[100005],vy[100005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            int x;
            scanf("%d",&x);
            vx[x].pb(i);
            vy[x].pb(j);
        }
    }
    LL sum=0;
    for(int i = 1;i<=100000;i++){
        LL sumx=0,cnt=0;
        sort(vx[i].begin(),vx[i].end());
        for(auto it:vx[i]){
            sum+=cnt*it-sumx;
            sumx+=it;
            cnt++;
        }
        cnt=0;
        sumx=0;
         sort(vy[i].begin(),vy[i].end());
        for(auto it:vy[i]){
            sum+=cnt*it-sumx;
            sumx+=it;
            cnt++;
        }
    //   printf("%lld\n",sum);
    }
    printf("%lld\n",sum);
}
int main(){
    int t=1;0000;
     // scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}