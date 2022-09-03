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
    int n,h,m;
    scanf("%d %d %d",&n,&h,&m);
    int x=h*60+m;
    int ans=1e9;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a=a*60+b;
        if(a<x)a+=1440;
        ans=min(ans,a-x);
    }
    printf("%d %d\n",ans/60,ans%60);
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