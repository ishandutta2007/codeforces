#include<bits/stdc++.h>
#pragma optimizer(O2)
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005

int main(){
    int n;
    scanf("%d",&n);
    LL a[300000];
 //   fill(vis,vis+n+1,0);
    int s;
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]==-1)s=i;
    }
    a[s]=0;
    for(int i = 0;i<s;i++)
        a[i]=0;
    LL ans=0;
    ans+=a[n-1];
    a[n-1]=1e9+1;
    int tmp=n/2;
    while(tmp>=2){
        int Min=1e9+1,Mini;
        for(int i = n-1;i>=tmp-1;i--){
            if(a[i]<Min){
                Min=a[i];
                Mini=i;
            }
        }
        ans+=Min;
        a[Mini]=1e9+1;
        tmp/=2;
    }
    printf("%lld\n",ans);
}