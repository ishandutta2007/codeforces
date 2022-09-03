#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
void solve(){
    int n;
    scanf("%d",&n);
    int a[1005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d\n",a[n-1]+a[n-2]);
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