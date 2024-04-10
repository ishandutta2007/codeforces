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
#define MXN 1000005
const int mod=1e9+7;
void solve(int T){
    int n;
    scanf("%d",&n);
    int a[305];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=2e9;
    for(int i = 1;i+1<n;i++){
        ans=min(ans,a[i+1]-a[i-1]);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
}

/*
*/