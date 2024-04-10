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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
LL cnt[100005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    reverse(a+1,a+n+1);
    LL sum=0;
    LL tmp=0;
    vector<pii> tmpm;
    for(int i = 1;i<=n;i++){
        vector<pii> v;
        LL sum2=0;
        for(auto it:tmpm){
            if(it.x<a[i]){
                v.pb(it);
            }
            else{
                sum2+=it.y;
            }
        }
        sum2++;
        LL tot=0;
        for(auto &it:v){
            LL len=(a[i]+it.x-1)/(it.x);
            LL val=a[i]/len;
            tot+=(len-1)*it.y;
            tot%=mod;
            cnt[val]+=it.y;
            it.x=val;
        }
        tmpm.clear();
        tmpm.pb(mp(a[i],sum2));
        for(auto it:v){
            if(cnt[it.x])tmpm.pb(mp(it.x,cnt[it.x]));
            cnt[it.x]=0;
        }
      //  for(auto it:tmpm){
         //   printf("%d %d\n",it.x,it.y);
      //  }
      //  printf("\n");
        tmp+=tot;
        tmp%=mod;
        sum+=tmp;
        sum%=mod;
      //  printf("%lld\n",sum);
    }
    printf("%lld\n",sum);
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
(k_1x+b)k_2+b=y
*/