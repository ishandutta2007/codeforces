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
#define MXN 3000000
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    int cnt[2]={0,0};
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]%=2;
        cnt[a[i]]++;
    }
    if(abs(cnt[0]-cnt[1])>1){
        printf("-1\n");
    }
    else{
        if(n%2==0){
            int ans1=0,ans2=0;
            int now1=0,now2=0;
            for(int i = 0;i<n;i++){
                if(a[i]==0){
                    ans1+=abs(now1-i);
                    now1+=2;
                }
                else{
                    ans2+=abs(now2-i);
                    now2+=2;
                }
            }
            printf("%d\n",min(ans1,ans2));
        }
        else{
            int ans= 0;
            if(cnt[0]>cnt[1]){
                
                int now=0;
                for(int i = 0;i<n;i++){
                    if(a[i]==0){
                        ans+=abs(i-now);
                        now+=2;
                    }
                }
            }
            else{
                int now=0;
                for(int i = 0;i<n;i++){
                    if(a[i]==1){
                        ans+=abs(i-now);
                        now+=2;
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
*/