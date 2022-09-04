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
int dp[80][80][1700];
int val[10000];
void solve(){   
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x==1)v.pb(i);
    }
    if(v.empty()){
        for(int i = 0;i<=n*(n-1)/2;i++){
            printf("0 ");
        }
        printf("\n");
        return;
    }
    LL tot=n-v.size();
    tot=tot*(tot-1)/2;
    for(int i = 0;i<80;i++){
        for(int j = 0;j<80;j++){
            for(int k = 0;k<1700;k++){
                dp[i][j][k]=10000;
            }
        }
    }
    for(int i = 0;i<n;i++){
        dp[0][i][abs(v[0]-i)]=i*(i-1)/2;
     //   printf("0 %d %d %d\n",i,abs(v[0]-i),dp[0][i][abs(v[0]-i)]);
    }
    for(int i = 1;i<v.size();i++){
        for(int k = 0;k<1700;k++){
            deque<pair<int,pii> > stk;
            stk.pb(mp(0,mp(-(i-1),dp[i-1][i-1][k]+((i-1)*(i-1)+3*(i-1))/2+1)));
            for(int j = i;j<n;j++){
                while(stk.size()>1){
                    auto p=stk.front();
                    stk.pop_front();
                    if(stk.front().x<j)continue;
                    stk.push_front(p);
                    break;
                }
                if(k+abs(v[i]-j)<1700){
                    dp[i][j][k+abs(v[i]-j)]=stk.front().y.y+(j*j-3*j)/2+stk.front().y.x*j;
                //    printf("%d %d %d %d %d %d\n",i,j,k+abs(v[i]-j),dp[i][j][k+abs(v[i]-j)],stk.front().y.x,stk.front().y.y);
                    assert(dp[i][j][k+abs(v[i]-j)]>=0);
                }
                LL x;
                LL a=-j;
                LL b=dp[i-1][j][k]+(j*j+3*j)/2+1;
                while(stk.size()){
                    auto p=stk.back();
                    x=(p.y.y-b)/(a-p.y.x);
                    if(x<=p.x){
                        stk.pop_back();
                    }
                    else{
                        break;
                    }
                }
                stk.pb(mp(x,mp(a,b)));
                //dp[i][j][k]=dp[i-1][a][k-abs(v[i][j])]+(j-a-1)*(j-a-2)/2;
                 //                                           (j*j+a*a+2-2ja-3j+3a)/2
                
            }
        }
    }
    for(int i = 0;i<10000;i++)val[i]=1e9;
    for(int i = 0;i<1700;i++){
        for(int j = 0;j<n;j++){
            val[i]=min(val[i],dp[v.size()-1][j][i]+(n-j-1)*(n-j-2)/2);
        }
    }
    int Min=tot;
    for(int i = 0;i<=n*(n-1)/2;i++){
        Min=min(Min,val[i]);
        printf("%lld ",tot-Min);
    }
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/