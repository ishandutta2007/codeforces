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

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[100005],b[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<m;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    LL Max=2e9,Min=-1;
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        int now=0;
        for(int i = 0;i<m;i++){
            while(now!=n&&a[now]>=b[i]-mid&&a[now]<=b[i]+mid)now++;
        }
        if(now==n){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    printf("%lld\n",Max);
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/