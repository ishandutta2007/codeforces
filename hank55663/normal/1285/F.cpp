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
vector<int> v[100005];
vector<int> num[100005];
int cnt[100005];
int mobe[100005];
int main(){
    fill(mobe,mobe+100005,1);
    for(int i = 1;i<100005;i++){
        for(int j=i;j<100005;j+=i){
            v[j].pb(i);
        }
        if(v[i].size()==2){
            for(int j=i;j<100005;j+=i){
                if(j/i%i==0){
                    mobe[j]=0;
                }
                else{
                    mobe[j]*=-1;
                }
            }
        }
    }
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(auto it:v[x]){
            num[it].pb(x/it);
        }
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        vector<int> stk;
        sort(num[i].begin(),num[i].end());
        reverse(num[i].begin(),num[i].end());
        num[i].pb(1);
        for(auto it:num[i]){
            int tot=0;
            for(auto it2:v[it]){
                tot+=cnt[it2]*mobe[it2];
            }
            if(tot==0){
                stk.pb(it);
                for(auto it2:v[it])cnt[it2]++;
            }
            else{
                while(tot){
                    int x=stk.back();
                    stk.pop_back();
                    for(auto it2:v[x])cnt[it2]--;
                    if(__gcd(x,it)==1){
                        tot--;
                    }
                    if(tot==0){
                        ans=max(ans,(LL)x*it*i);
                    }
                }
            }
        }
        while(!stk.empty()){
            int x=stk.back();
            stk.pop_back();
            for(auto it:v[x])cnt[it]--;
        }
    }
    printf("%lld\n",ans);
}