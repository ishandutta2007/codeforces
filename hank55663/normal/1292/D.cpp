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
vector<int> v[5005];
vector<int> prime;
int noprime[5005];
int cnt[5005];
void dfs(int l,int r,LL &ans,int level,int n){
    int tot[5005];
    MEM(tot);
    for(int i=l;i<=r;i++){
        if(v[i].size()>=level)
        tot[v[i][v[i].size()-level]]+=cnt[i];
    }
    int Max=0,Maxi;
    for(int i = 0;i<5005;i++){
        if(tot[i]>Max){
            Max=tot[i];
            Maxi=i;
        }
    }
    if(Max*2<=n)return;
    else{
        ans=ans-Max+n-Max;
        //int ok[3005];
        //MEM(ok);
        int ll=5005,rr=0;
        //printf("!%d %d %d\n",l,r,level);
        for(int i = l;i<=r;i++){
            if(v[i].size()>=level&&v[i][v[i].size()-level]==Maxi){
        //        ok[i]=1;
                ll=min(ll,i);
                rr=max(rr,i);
            }
        }
     /*   for(int i = l;i<=r;i++){
        //    printf("%d %d %d %d\n",i,ll,rr,!ok[i]&&i>=ll&&i<=rr);
            assert(!(!ok[i]&&i>=ll&&i<=rr));
        }*/
        //printf("??%d %d %d\n",ll,rr,Maxi);
        dfs(ll,rr,ans,level+1,n);
    }
}
int main(){
    for(int i = 2;i<5005;i++){
        if(!noprime[i]){
            prime.pb(i);
            for(int j=i*2;j<5005;j+=i)noprime[j]=1;
        }
    }
    for(int i = 2;i<=5000;i++){
        for(auto it:prime){
            int tmp=i;
            while(tmp){
                for(int j=0;j<tmp/it;j++)
                v[i].pb(it);
                tmp/=it;
            }
        }
    }
    int n;
    scanf("%d",&n);
    LL ans=0;
    for(int i = 1;i<=n;i++){
        int k=5000;
        scanf("%d",&k);
        cnt[k]++;
        ans+=v[k].size();
    }
    dfs(0,5000,ans,1,n);
    printf("%lld\n",ans);
}
/*
2 6
5 7
7 5
4 3
6 4
7 3
6 5
5 7
3 6
4 7
*/
//a+a+1=10a+1
//3a+2=10a+2