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
#define MXN 200005
int mod=998244353;
void solve(){
    int l,r;
    scanf("%d %d",&l,&r);
    int cnt[20],cnt2[20];
    MEM(cnt);
    for(int i = l;i<=r;i++){
        for(int j= 0;j<20;j++){
            if(i&(1<<j)){
                cnt[j]++;
            }
        }
    }
    MEM(cnt2);
    for(int i = l;i<=r;i++){
        int x;
        scanf("%d",&x);
        for(int j  =0;j<20;j++){
            if(x&(1<<j)){
                cnt2[j]++;
            }
        }
    }
    LL ans=0;
    for(int i = 0;i<20;i++){
        if(cnt[i]==cnt2[i]);
        else ans+=(1<<i);
        //printf("%d %d\n",cnt[i],cnt2)
    }
    printf("%lld\n",ans);
}  
 
 
int main(){
    int t=1;0000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
 
*/