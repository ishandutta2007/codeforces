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
int dfs(int i,int m,int n,int sum){
    if(i<0){
        return 2e9;
    }
    if(m&(1<<i)){
       return dfs(i-1,m,n,sum+(1<<i));
    }
    else{
        int ans=(((m|(1<<i))^n)>>i)<<i;
        return min(ans,dfs(i-1,m,n,sum));
    }
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n>m){
        printf("0\n");
    }
    else{
        printf("%d\n",dfs(30,m,n,0));
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/