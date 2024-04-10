#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;

void solve(){   
    LL a,b,x,y,n;
    scanf("%lld %lld %lld %lld %lld",&a,&b,&x,&y,&n);
    if(a-x+b-y<=n){
        printf("%lld\n",x*y);
    }
    else{
        LL ans1,ans2;
        {
            LL less=n;
            if(a-x>less)ans1=(a-less)*b;
            else{
                less-=a-x;
                ans1=x*(b-less);
            }
        }
        {
            LL less=n;
            if(b-y>less)ans2=(b-less)*a;
            else{
                less-=b-y;
                ans2=y*(a-less);
            }
        }
        printf("%lld\n",min(ans1,ans2));
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/