#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int myrand(int n){
    return ((((((LL)rand())<<20)+rand())<<10)+rand())%n;
}
int main(){
    int n;
    scanf("%d",&n);
    int ans=n;
    LL a[200005];
    vector<LL> v;
    LL Min=1e12;
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=1)v.pb(a[i]);
        Min=min(Min,a[i]);
    }
    if(v.empty()){
        printf("%d\n",n);
        return 0;
    }
    for(int i = 0;i<25;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(a[j]<prime[i])sum+=prime[i]-a[j];
            else sum+=min(a[j]%prime[i],prime[i]-a[j]%prime[i]);
        }
        ans=min(ans,sum);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    srand(time(NULL));
    random_shuffle(v.begin(),v.end(),myrand);
    int cnt=0;
    for(int t=0;t<v.size()&&cnt<50000000;t++){
        //LL x=(((LL)rand()<<20)+rand())%v.size();
        for(LL ii = max(-v[t]+2,-10ll);ii<=+10;ii++){
            vector<LL> prime;
            LL tmp=v[t]+ii;
            for(LL j=2;j*j<=tmp;j++){
                cnt++;
                if(tmp%j==0){
                    prime.pb(j);
                    while(tmp%j==0)tmp/=j;
                }
            }
            if(tmp!=1)prime.pb(tmp);
            for(auto it:prime){
                LL sum=0;
                for(int j=0;j<n;j++){
                    cnt++;
                    if(a[j]<it)sum+=it-a[j];
                    else{
                        sum+=min(a[j]%it,it-a[j]%it);
                    }
                    if(sum>=ans)break;
                
                }
                ans=min((LL)ans,sum);
            }
        }
    }
    printf("%d\n",ans);
}