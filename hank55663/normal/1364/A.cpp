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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d %d",&n,&x);
        int pre[100005];
        pre[0]=0;
        int sum=0;
        int a=0,ax=0,b=1e9,bx=0;
        int ans=-1;
        for(int i = 1;i<=n;i++){
            int a;
            scanf("%d",&a);
            sum+=a;
            sum%=x;
            pre[i]=sum;
        }
        for(int i = 1;i<=n;i++){
            if(pre[i]!=0)ans=max(ans,i);
            if(pre[i]!=pre[n])ans=max(ans,n-i);
        }
        
        printf("%d\n",ans);
    }
}