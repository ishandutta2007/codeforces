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
#define double long double
using namespace std;
LL pre[100005];
LL suf[100005];
int a[100005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=pre[i-1]+max(a[i-1]-a[i],0);
    }
    for(int i = n;i>=1;i--){
        suf[i]=suf[i+1]+max(a[i+1]-a[i],0);
    }
    while(m--){
        int s,t;
        scanf("%d %d",&s,&t);
        if(s<t)
        printf("%lld\n",pre[t]-pre[s]);
        else 
        printf("%lld\n",suf[t]-suf[s]);
    }
}
int main(){
    int t=1;000;
   // scanf("%d",&t);
    while(t--){
       
        solve();
    }
    
}
/*
*/