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
        int a[3];
        for(int i = 0;i<3;i++)
            scanf("%d",&a[i]);
        sort(a,a+3);
        int ans=max(a[1]-a[0]-1,0)+max(a[2]-a[1]-1,0)+max(a[2]-a[0]-2,0);
        if(a[1]==a[0]||a[2]==a[1])ans--;
        ans=max(ans,0);
        //a[0]++;
        //a[2]--
        printf("%d\n",ans);
    }
}