#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define N (1<<20)
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int cnt[1005];
    MEM(cnt);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++; 
    }
    int ans=0,tmp=0;
    for(int i = 1;i<=k;i++){
        ans+=cnt[i]/2*2;
        tmp+=cnt[i]%2;
    }
    printf("%d\n",ans+(tmp+1)/2);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/