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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
LL Min[100005][60];
LL v[100005][60];
LL sum[100005][60];
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        v[i][0]=x;
    }
    for(int i =  0;i<n;i++){
        int w;
        scanf("%d",&w);
        sum[i][0]=Min[i][0]=w;
    }
    for(int i = 1;i<60;i++){
        for(int j = 0;j<n;j++){
            v[j][i]=v[v[j][i-1]][i-1];
            sum[j][i]=sum[j][i-1]+sum[v[j][i-1]][i-1];
            Min[j][i]=min(Min[j][i-1],Min[v[j][i-1]][i-1]);
        }
    }
    for(int i = 0;i<n;i++){
        LL now=i;
        LL res=0,res2=1e9;
        for(int j=0;j<60;j++){
            if((1ll<<j)&k){
                res+=sum[now][j];
                res2=min(res2,Min[now][j]);
                now=v[now][j];   
            }
        }
        printf("%lld %lld\n",res,res2);
    }
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/