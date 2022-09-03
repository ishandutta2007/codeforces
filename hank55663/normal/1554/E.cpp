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
vector<int> v[100005];
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int ok=1;
int dfs(int x,int f,int k){
    int cnt=0;
    for(auto it:v[x]){
        if(it!=f){
            cnt+=dfs(it,x,k);
            if(!ok)return 1;
        }
    }
   // printf("%d %d\n",x,cnt);
    if(cnt%k==0)return 1;
    if((cnt+1)%k==0)return 0;
    ok=0;
    return 1;
}
void solve(){
    int n=rand()%10+1;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x=i+1,y=rand()%i+1;
        scanf("%d %d",&x,&y);
       //printf("%d %d\n",x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    int ans[100005];
    fill(ans,ans+n+1,0);
    ans[1]=f_pow(2,n-1);
    for(int i = 1;i<=n;i++){
        if(v[i].size()==1){
            int tot=0;
            for(auto it:v[v[i][0]]){
                if(v[it].size()!=1)tot++;
            }
            if(tot<=1){
                int x=v[i][0];
                for(int j = 2;j<=n;j++){
                    if(v[x].size()%j==0||(v[x].size()-1)%j==0){
                
                        ok=1;
                        if(dfs(1,0,j)==1&&ok)ans[j]=1;
                        //    printf("??%d %d %d\n",j,x,ans[j]);
                    }
                }
                break;
            }
        }
    }
   /* for(int i = 2;i<=n;i++){
        ok=1;
        printf("%d ",ans[i]);
        if(dfs(1,0,i)&&ok){
            printf("1\n");
            assert(ans[i]==1);
        }
        else{
            printf("0\n");
            assert(ans[i]==0);
        }
    }*/
    for(int i = 2;i<=n;i++){
        int tot=0;
        for(int j = i*2;j<=n;j+=i){
            tot+=ans[j];
        }
        if(tot)ans[i]=0;
        ans[1]-=ans[i];
        if(ans[1]<0)ans[1]+=mod;
    }
    for(int i = 1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/