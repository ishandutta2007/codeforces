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
#define MXN 100005
vector<pii> E[2005];
int main() {
    int n;
    scanf("%d",&n);
    vector<pii> v;
    //graph.init(n);
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            scanf(" %c",&c);
            if(c=='1'){
                v.pb(mp(i,j));
                E[i].pb(mp(i,j));
                E[j].pb(mp(i,j));
     //           graph.add_edge(i,j);
            }
        }
    }
    if(n>10){
        int cnt[2005];
        int tmp[2005];
        MEM(cnt);
        MEM(tmp);
        for(auto it:v)cnt[it.x]++,tmp[it.x]++;
        sort(cnt,cnt+n);
        //reverse(cnt,cnt+n);
        int ok=1;
        int tot=0;
        for(int i = 0;i<n-1;i++){
            tot+=cnt[i];
            if(tot==(i)*(i+1)/2){
                ok=0;
            }
        }
        if(ok){
            printf("0 1\n");
        }
        else{
            LL ans=0;
            for(int i = 0;i<n;i++){
                for(int j=0;j<n;j++){
                    cnt[j]=tmp[j];
                }
                for(auto it:E[i]){
                    if(it.x==i)cnt[i]--,cnt[it.y]++;
                    else cnt[i]++,cnt[it.x]--;
                }
                sort(cnt,cnt+n);
                //reverse(cnt,cnt+n);
                int tot=0,ok=1;
                for(int i = 0;i<n-1;i++){
                    tot+=cnt[i];
                    if(tot==i*(i+1)/2)ok=0;
                }
                ans+=ok;
            }
            printf("1 %lld\n",ans);
        }
    }
    else{
        int Min=1e9,ans=0;
        for(int i = 0;i<(1<<n);i++){
            int cnt[20];
            MEM(cnt);
            for(auto it:v){
                int a=i&(1<<it.x),b=i&(1<<it.y);
                if((a&&b)||(!a&&!b))cnt[it.x]++;
                else cnt[it.y]++;
            }
            sort(cnt,cnt+n);
            int tot=0;
            int ok=1;
            for(int j=0;j<n-1;j++){
                tot+=cnt[j];
                if(tot==j*(j+1)/2)ok=0;
            }
            if(ok){
                int num=__builtin_popcount(i);
                if(Min>num)Min=num,ans=0;
                if(Min==num)ans++;
            }
        }
        if(ans==0)printf("-1\n");
        else{
            for(int i =1;i<=Min;i++)ans*=i;
            printf("%d %d\n",Min,ans);

        }
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/