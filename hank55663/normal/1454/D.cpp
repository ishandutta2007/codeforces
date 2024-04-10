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
#define next Next
using namespace std;
void solve(){
    LL n;
    scanf("%lld",&n);
    map<LL,int> m;
    for(LL i = 2;i*i<=n;i++){
        while(n%i==0){
            m[i]++;
            n/=i;
        }
    }
    if(n!=1)m[n]++;
    LL ans[1005];
    int Max=0;
    LL Maxi;
    for(auto it:m){
        if(it.y>Max){
            Max=it.y;
            Maxi=it.x;
        }
    }
    for(int i = 0;i<Max;i++)ans[i]=Maxi;
    for(auto it:m){
        if(it.x!=Maxi){
            for(int j = 0;j<it.y;j++){
                ans[Max-1]*=it.x;
            }
        }
    }
    printf("%d\n",Max);
    for(int i = 0;i<Max;i++){
        printf("%lld ",ans[i]);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}