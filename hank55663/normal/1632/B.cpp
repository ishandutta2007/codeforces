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
    int n;
    scanf("%d",&n);
    int i
    ;
    for(i = n-1;;i--){
        printf("%d ",i);
        if(__builtin_popcount(i)==1){
            break;
        }
    }
    for(int j = 0;j<i;j++)printf("%d ",j);
    printf("\n");
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