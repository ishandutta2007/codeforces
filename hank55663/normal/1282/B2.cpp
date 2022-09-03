
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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,p,k;
        scanf("%d %d %d",&n,&p,&k);
        LL a[200005];
        a[0]=0;
        for(int i = 1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n+1);
        for(int i = 1;i<k;i++)
            a[i]+=a[i-1];
        int ans=0;
        for(int i = k;i<=n;i++){
            a[i]+=a[i-k];
        }
        for(int i = 1;i<=n;i++){
            if(a[i]<=p){
                ans=i;
            }
        }
        printf("%d\n",ans);

    }
}