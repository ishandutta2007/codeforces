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
const int mod=998244353;
void solve(){
//    vector<int> v;
    int n,k;
    scanf("%d %d",&n,&k);
    int v[1000005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    for(int i = n;i>n-k;i--){
        if(v[i]==-1)v[i]=0;
        if(v[i]!=0){
            printf("0\n");
            return;
        }
    }
    LL ans=1;
    for(int i = 1;i<=n;i++){
        if(v[i]==-1){
            ans=ans*(min(n-i+1,k+1)+(i-1));
        }
        else if(v[i]==0){
            ans=ans*min(n-i+1,k+1);
        }
        ans%=mod;
        if(v[i]>=i)ans=0;
    }
    printf("%lld\n",ans);
    /*vector<int> tmp;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        tmp.pb(x);
    }
    for(int i = 1;i<=n;i++)
    v.pb(i);
    int cnt[5];
    MEM(cnt);
    do{
        auto p=v;
        for(int t=0;;t++){
            int ok=1;
            for(int i = 0;i+1<p.size();i++){
                if(p[i]>p[i+1])ok=0;
            }
            if(p==tmp){
                cnt[t]++;
                break;
            }
            if(ok){
               // cnt[t]++;
                break;
            }
            for(int i = 0;i+1<p.size();i++){
                if(p[i]>p[i+1])swap(p[i],p[i+1]);
            
            }
        }
    }while(next_permutation(v.begin(),v.end()));
    for(int i = 0;i<n;i++){
        printf("%d ",cnt[i]);
    }
    printf("\n");*/
}  
int main(){
   // srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}