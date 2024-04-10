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
const int mod=998244353;
void solve(){
    int a,b;
    scanf("%d %d",&a,&b);
    int ans=b-a;
    for(int i = 0;i<=b-a;i++){
        ans=min((b|(a+i))-b+i+1,ans);
    }
    for(int i = 0;i<=2*b;i++){
        ans=min(((b+i)|a)-b+1,ans);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567
*/