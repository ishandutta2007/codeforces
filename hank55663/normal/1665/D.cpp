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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
vector<int> v[200005];
int x=123;
/*int qu(int a,int b){
    return __gcd(a+x,b+x);
}*/
void solve(){
   // scanf("%d",&x);
    int a=1;
    for(int i = 1;i<=30;i++){
        int b=a+(1<<i);
        printf("? %d %d\n",a,b);
        fflush(stdout);
        int x;//=qu(a,b);
        scanf("%d",&x);
        if(x!=(1<<i)){
            a+=(1<<(i-1));
        }
    }
    printf("! %d\n",(1<<30)-a);
    fflush(stdout);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/