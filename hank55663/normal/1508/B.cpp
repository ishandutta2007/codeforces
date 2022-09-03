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
LL p2[100005];
void solve(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    if(p2[n-1]<k){
        printf("-1\n");
        return;
    }
    k--;
    vector<int> ans;
    for(int i = 1;i<=n;){
        for(int j = i;;j++){
            if(j==n){
                for(int k = j;k>=i;k--){
                    ans.pb(k);
                }
                i=j+1;
                break;
            }
            if(p2[n-j-1]<=k){
                k-=p2[n-j-1];
            }
            else{
                for(int k =j;k>=i;k--){
                    ans.pb(k);
                }
                i=j+1;
                break;
            }
        }
    }
    for(auto it:ans){
        printf("%d ",it);
    }
    printf("\n");
}
int main(){
    LL Max=1e9;
    Max=Max*Max;
    p2[0]=1;
    for(int i = 1;i<=100000;i++){
        p2[i]=p2[i-1]*2;
        if(p2[i]>Max){
            p2[i]=Max;
        }
    }
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/