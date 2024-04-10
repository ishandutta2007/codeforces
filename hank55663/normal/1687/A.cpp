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
    int n,k;
    scanf("%d %d",&n,&k);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    LL ans=0;
    if(k>=n){
        for(int i = 0;i<n;i++){
            ans+=a[i];
            ans+=k-i-1;
        }
        printf("%lld\n",ans);
    }
    else{
        LL pre[200005];
        pre[0]=0;
        for(int i = 1;i<=n;i++){
            pre[i]=pre[i-1]+a[i-1];
            if(i>=k){
                ans=max(ans,pre[i]-pre[i-k]+(k*1ll*(k-1))/2);
            }
        }
        printf("%lld\n",ans);
    }
} 

int main(){
   
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
0 1 2 3 4 5 6 7 
0 1 6 7 4 5 2 3
0 3 2 5 4 7 6 1
0 3 6 1 4 7 2 5
0 5 2 7 4 1 6 3
0 5 6 3 4 1 2 7
0 7 2 1 4 3 6 5
0 7 6 5 4 3 2 1
    a=p*1+(1-p)*(1+t2+a)
    a=p+q+q*t2+q*a
    a=(p+q+q*t2)/(1-q)
*/
/*
0 0 0 0
1 2 1 4
1 0 1 0
3 3 3 3
3 1 2 2
4 1 2 1
2 0 2 0

1 4 2 7 5 6 3
*/