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
    int n;
    scanf("%d",&n);
    int ans=1;
    int now=1;
    int a[100005];
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i =2;i<=n;i++){
        if(a[i]>a[i-1])now++;
        else now=1;
        ans=max(ans,now);
    }
    printf("%d\n",ans);
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/