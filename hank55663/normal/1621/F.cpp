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
#define index Index
void solve(){
    LL n,a,b,c;
    scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
    char s[100005];
    scanf("%s",s);
    LL cnt[2]={0,0};
    LL less[2]={0,0};
    for(int i = 1;s[i]!=0;i++){
        if(s[i]==s[i-1])cnt[s[i]-'0']++;
    }
    if(s[0]=='0')less[0]++;
    if(s[n-1]=='0')less[0]++;
   // less[s[0]-'0']++;
    int ffirst=1;
    int tot=0;
    vector<LL> v;
    for(int i=0;s[i]!=0;i++){
        if(s[i]=='1'){
            if(ffirst);
            else if(s[i]!=s[i-1]){
                v.pb(tot);
            }
            tot=0;
            ffirst=0;
        }
        else{
            tot++;
        }
    }
    LL ans=0;
       LL sum=0;
    for(int i = 0;i<=less[0];i++){
        ans=max(min(cnt[0],cnt[1]+1)*a+min(cnt[0]-1,cnt[1])*b+sum,ans);
        ans=max(min(cnt[1],cnt[0]+1)*b+min(cnt[1]-1,cnt[0])*a+sum,ans);
        ans=max(min(cnt[1],cnt[0])*b+min(cnt[1],cnt[0])*a+sum,ans);
        cnt[0]++;
        sum-=a+c;
    }
    cnt[0]-=less[0]+1;
    sum+=(a+c)*(less[0]+1);
    sort(v.begin(),v.end());
 
    LL x=0,y=0;
    for(auto it:v){
        sum+=(it-1)*a-c+b;
        x+=it;
        y++;
        cnt[0]-=it-1;
        int need=x-y;
        if(need>=0){
            sum+=need*b;
            cnt[1]-=need;
            y+=need;
        }
        if(cnt[0]>=0&&cnt[1]>=0){
            ans=max(ans,sum);
            if(x==y){
                for(int i = 0;i<=less[0];i++){
                    ans=max(min(cnt[0],cnt[1]+1)*a+min(cnt[0]-1,cnt[1])*b+sum,ans);
                    ans=max(min(cnt[1],cnt[0]+1)*b+min(cnt[1]-1,cnt[0])*a+sum,ans);
                    ans=max(min(cnt[1],cnt[0])*b+min(cnt[1],cnt[0])*a+sum,ans);
                    cnt[0]++;
                    sum-=a+c;
                }
                cnt[0]-=less[0]+1;
                sum+=(a+c)*(less[0]+1);
            }
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
8876666554222188 
*/