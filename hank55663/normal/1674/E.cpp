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
#define index Index
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans=1e9;
    for(int i = 0;i+2<n;i++){
        ans=min(ans,min(a[i],a[i+2])+(abs(a[i+2]-a[i])+1)/2);
    }
    for(int i = 0;i+1<n;i++){
        ans=min(ans,max((a[i]+1)/2,max((a[i+1]+1)/2,(a[i]+a[i+1]+2)/3)));
    }
    sort(a,a+n);
    ans=min(ans,(a[0]+1)/2+(a[1]+1)/2);
    printf("%d\n",ans);
}
int main(){
    srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
  40018/76270
*/