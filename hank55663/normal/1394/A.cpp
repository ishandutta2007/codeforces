#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
void solve(){
    int n,d,m;
    scanf("%d %d %d",&n,&d,&m);
    LL a[100005];
    LL b[100005];
    int cnta=0, cntb=0;
    MEM(a);
    MEM(b);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x>m){
            a[++cnta]=x;
        }
        else{
            b[++cntb]=x;
        }
    }
    sort(a+1,a+cnta+1);
    reverse(a+1,a+cnta+1);
    sort(b+1,b+cntb+1);
    reverse(b+1,b+cntb+1);
    for(int i = 1;i<=n;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    LL ans=0;
    for(int i = 0;i<=cnta;i++){
        if(n-max(0,i-1)*d-i<0)break;
        ans=max(ans,a[i]+b[n-max(0,i-1)*d-i]);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/