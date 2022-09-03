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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,dd;
        scanf("%d %d",&n,&dd);
        int tn=n;
        int d[5005];
        fill(d,d+5005,0);
        d[0]=1;
        n--;
        LL sum=0;
        int i;
        for(i = 1;n;i++){
            d[i]=min(d[i-1]*2,n);
            n-=d[i];
            sum+=i*d[i];
            if(!n)break;
        }
        n=tn;
        if(sum>dd||dd>n*(n-1)/2){
            printf("NO\n");// %d %d %d\n",sum,dd,n*(n-1)/2);
        }
        else{
            int Max=i;
            for(int j=0;j<dd-sum;j++){
            for(int i = Max;i>=0;i--){
                if(d[i]!=1){
                    d[i]--;
                    d[i+1]++;
                    Max=max(Max,i+1);
                    break;
                }
            }
            }
            printf("YES\n");
            vector<vector<int> >v(Max+1);
            int now=1;
            for(int i = 0;i<=Max;i++){
                for(int j=0;j<d[i];j++){
                    v[i].pb(now++);
                }
            }
            for(int i = 1;i<=Max;i++){
                for(int j=0;j<v[i].size();j++){
                    printf("%d ",v[i-1][j/2]);
                }
            }
            printf("\n");
        }
    }
}