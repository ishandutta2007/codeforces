
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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
LL dp[50];
LL fra[55];
LL Max=1000000000000000001ll;
LL pro(LL a,LL b){
    LL res=0,temp=a;
    while(b){
        if(b&1)res=min(res+temp,Max);
        temp=min(temp+temp,Max);
        b>>=1;
    }
    return res;
}
/*
1 2 3
1 3 2
2 1 3
2 3 1X
3 2 1 X
3 1 2

*/
bool check(vector<int> res){
    int now=res.back();
    do{
        if(now>res.size())return false;
        now=res[now-1];
    }while(now!=res.back());
    return true;
}
vector<int> Next(vector<int> v,LL k){
    set<int> s;
    for(int i = 1;i<v.size();i++){
        s.insert(v[i]);
    }
    vector<int> res{v[0]};
    for(int i = 1;i<v.size();i++){
        if(i==v.size()-1){
            res.pb(*s.begin());
            break;
        }
        for(auto it:s){
            res.pb(it);
            if(check(res)){
                res.pop_back();
                continue;
            }
            res.pop_back();
            if(k<fra[max((int)v.size()-i-2,0)]){
                res.pb(it);
                s.erase(it);
                break;
            }
            k-=fra[max((int)v.size()-i-2,0)];
        }
        //printf("%d\n",i);
    }
    return res;
}
vector<int> go(int n,LL k){
    if(n==0)return vector<int>();
    for(int i = 1;i<=n;i++){
        if(pro(dp[n-i],fra[max(i-2,0)])<=k){
            k-=pro(dp[n-i],fra[max(i-2,0)]);
        }
        else{
            vector<int> v;
            v.pb(i);
            for(int j=1;j<i;j++)
                v.pb(j);
            v=Next(v,k/dp[n-i]);
            k%=dp[n-i];
            vector<int> res2=go(n-i,k);
            for(auto &it:res2){
                it+=i;
                v.pb(it);
            }
            return v;
        }
    }
}
int main(){
    fra[0]=1;
    for(int i =1;i<=50;i++){
        fra[i]=pro(fra[i-1],i);
    }
    dp[0]=1;
    for(int i=1;i<=50;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]+=pro(dp[j],fra[max(i-j-2,0)]);
            dp[i]=min(dp[i],Max);
        }
    }
   // vector<int> v{4,1,2,3};
   /* for(auto it:Next(v,0)){
        printf("%d ",it);
    }
    printf("\n");
    for(auto it:Next(v,1)){
        printf("%d ",it);
    }
    printf("\n");
    for(auto it:Next(v,2)){
        printf("%d ",it);
    }*/
    /*while(true){
        for(auto it:v)printf("%d ",it);
        printf("\n");
        v=Next(v);
        if(v.empty())break;
    }*/
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,k;
        scanf("%lld %lld",&n,&k);
    //    printf("%lld\n",dp[n]);
        if(dp[n]>=k){
            k--;
            vector<int> res=go(n,k);
            for(auto it:res)
            printf("%d ",it);
            printf("\n");
        }
        else{
            printf("-1\n");
        }
    }
    //printf("%lld\n",ans);
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/