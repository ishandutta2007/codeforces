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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt[200005];
void solve(){
    map<int,int> m;
    int n;
    scanf("%d",&n);
    fill(cnt,cnt+n+1,0);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    LL tmp=0;
    vector<int> v;
    int ok=1;
    for(int i = 0;i<=n;i++){
        if(ok)printf("%lld ",tmp+cnt[i]);
        else{
            printf("-1 ");
        }
        for(int j = 0;j<cnt[i]-1;j++)v.pb(i);
        if(!cnt[i]){
            if(v.empty()){
                ok=0;
            }
            else{
            tmp+=i-v.back();
            v.pop_back();
            }
        }
    
    }
    printf("\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}