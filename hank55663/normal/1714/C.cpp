#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int s;
    scanf("%d",&s);
    int ans=1e9+100;
    for(int i = 0;i<(1<<10);i++){
        int x=__builtin_popcount(i);
        int res=0;
        int sum=0;
        for(int j = 1;j<=9;j++){
            if(i&(1<<j)){
                sum+=j;
                res=res*10+j;
            }
        }
        if(sum==s)ans=min(ans,res);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/