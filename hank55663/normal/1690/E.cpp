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
int cnt[1005];
void solve(){
    int n,k;
    MEM(cnt);
    scanf("%d %d",&n,&k);
    LL ans=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        ans+=x/k;
        cnt[x%k]++;
    }
    int l=1;
    for(int i = k-1;i>0;i--){
        l=max(l,k-i);
        while(cnt[i]){
          //  printf("?\n");
            if(l>=k)break;
            while(!cnt[l]&&l<k)l++;
            if(l>=k)break;
            if(i==l&&cnt[i]==1)break;
            while(cnt[i]&&cnt[l]){
                if(i==l&&cnt[i]==1)break;
                cnt[i]--;
                cnt[l]--;
                ans++;
            }
        }
    }
    printf("%lld\n",ans);
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}