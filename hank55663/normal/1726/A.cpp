#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    int n;
    scanf("%d",&n);
    int a[2005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    if(n==1){
        printf("0\n");
        return;
    }
    int ans=a[n]-a[1];
    for(int i = 1;i<n;i++){
        ans=max(ans,a[i]-a[i+1]);
        if(i!=1)
        ans=max(ans,a[i]-a[1]);
        ans=max(ans,a[n]-a[i]);
    }
    printf("%d\n",ans);

}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
4999850001
6
1 8 4 6 8 10
2 1
3 1
4 3
5 4
6 3
1 2 1
1 3 1
3 4 1
4 5 1
3 6 1
*/