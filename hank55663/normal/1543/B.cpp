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
    int a[200005];
    LL tot=0;
    for(int i = 0;i<n;i++)scanf("%d",&a[i]),tot+=a[i];
    printf("%lld\n",tot%n*(n-tot%n));
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}