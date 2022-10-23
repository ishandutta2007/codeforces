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
void solve(int T){
    int n,k;
    scanf("%d",&n);
    int a[100005];
    int pre[100005];
    int ok=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
//        if(a[i])ok=1;
        pre[i]=pre[i-1]+a[i];
    }
    int cnt=0;
    int ans=n;
    for(int i = n;i>=0;i--){
        ans=min(ans,max(cnt-pre[i],0)+pre[i]);
        if(a[i]==0)cnt++;
    }
    printf("%d\n",ans);
    

}

int main(){
    int t=1;
     scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*

*/