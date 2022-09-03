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
using namespace std;
#define MXN 100005
int val[2005][2005];
void solve(){
    LL k;
    scanf("%lld",&k);
    if(k%2==1){
        printf("-1\n");
    }
    else{
        vector<LL> v;
        v.pb(0);
        for(LL i = 1;i<60;i++){
            LL dd=1ll<<i;
            LL sum=0;
            for(LL j = 1;j<=i;j++){
                dd/=2;
                sum+=dd*j;
                
            }
            sum+=dd*i;
            v.pb(sum);
          //  printf("%lld\n",sum);
        }
        vector<int> ans;
        int sum=0;
        for(int i = v.size()-1;i>0;i--){
           // printf("i:%d %d\n",i,v[i]);
            while(k>=v[i]){
                k-=v[i];
                ans.pb(i);
                sum+=i;
                if(sum>2000){
                    printf("-1\n");
                    return;
                }
            }
           // printf("%lld\n",k);
        }
        /*
        int sum=0;
        for(int i = 1;i<60;i++){
            if(k&(1ll<<i)){
                v.pb(i);
                sum+=i;
            }
        }*/
        printf("%d\n",sum);
        printf("1");
        for(int i=0;i<ans.size();i++){//ans){
            auto it=ans[i];
            for(int j = 1;j<it;j++)printf(" 0");
            if(i!=ans.size()-1)
            printf(" %d",1);
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}
/*
*/