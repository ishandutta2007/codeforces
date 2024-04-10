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
#define MXN 3005
#define next Next
int main(){
    int n;
    scanf("%d",&n);
    int ans[100005];
    fill(ans,ans+n+1,0);
    int color=1;
    for(int i = 2;i<=n;i++){
        if(ans[i]==0){
            for(int j=i;j<=n;j+=i){
                ans[j]=color;
            }
            color++;
        }
    }
    for(int i=2;i<=n;i++)
        printf("%d ",ans[i]);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/