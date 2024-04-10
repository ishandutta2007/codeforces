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
#define MXN 15000
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v[64];
    LL a[200005];
    for(int i = 1;i<=n;i++){
        LL x;
        scanf("%lld",&x);
        a[i]=x;
        for(int j = 0;;j++){
            if(x%2==1){
                v[j].pb(i);
                break;
            }
            else{
                x/=2;
            }
        }
    }
    int Max=0;
    for(int i = 0;i<64;i++){
        Max=max(Max,(int)v[i].size());
    }
    for(int i = 0;i<64;i++){
        if(v[i].size()==Max){
            int ans[200005];
            fill(ans,ans+n+1,0);
            for(auto it:v[i]){
                ans[it]=1;
            }
            vector<int> res;
            for(int j=1;j<=n;j++){
                if(ans[j]==0)
                    res.pb(j);
            }
            printf("%d\n",res.size());
            for(auto it:res){
                printf("%lld ",a[it]);
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}