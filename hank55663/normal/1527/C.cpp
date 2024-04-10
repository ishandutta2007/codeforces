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
#define last Last
#define MXN 200005
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    map<int,vector<int> > m;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        m[a[i]].pb(i);
    }
    LL ans=0;
    for(auto it:m){
        LL sum=0;
        for(auto it2:it.y){
            ans+=sum*(n-it2+1);
            sum+=it2; 
         //   printf("%lld %lld\n",ans,sum);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*

*/