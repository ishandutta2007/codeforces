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
int has[300005];
int val[300005];
int Max[300005];
int f[300005];
int cnt[300005];

LL ans;
//int cnt=0;
int Find(int x){
    //cnt++;
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    LL tmp=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
      //  a[i]=rand()%200001;
        f[i]=i;
        has[a[i]]=1;
        val[a[i]]=i;//.pb(i);
        cnt[a[i]]++;
        ans+=-a[i];
        tmp+=-a[i];
    }
    a[n]=0;
    f[n]=n;
    has[0]=1;
    val[0]=n;
    cnt[0]++;
    for(int i = (1<<18)-1;i>=0;i--){
        for(int a=i;a;a=(a-1)&i){
            int b=i-a;
            if(has[a]&&has[b]){
                if(Find(val[a])!=Find(val[b])){
                    ans+=(cnt[a]+cnt[b]-1)*(LL)(i);
                    cnt[a]=1,cnt[b]=1;
                    f[Find(val[a])]=Find(val[b]);
                }
            }
        }
    }
    printf("%lld\n",ans);
}