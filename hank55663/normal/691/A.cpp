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
    int a[1005];
    int tot=0;
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]),tot+=a[i];
    if(n==1){
        if(tot)printf("YES\n");
        else printf("NO\n");
    }
    else if(tot==n-1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/