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
    int ans=1;
    while((ans<<1)<=n)ans<<=1;
    ans--;
    printf("%d\n",ans);
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