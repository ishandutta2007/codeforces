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
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    LL lcm=1;
    int ok=1;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        lcm=lcm*(i+1)/__gcd(lcm,i*1ll+1);
        if(lcm>1e9)lcm=1e9+1;
        if(a[i]%lcm==0){
            ok=0;
        }
    }
    if(ok)printf("Yes\n");
    else printf("No\n");
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/