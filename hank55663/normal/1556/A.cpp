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
#define MXN 3000000
const int mod=998244353;
void solve(){
    int a,b;
    scanf("%d %d",&a,&b);
    if((a+b)%2==1)printf("-1\n");
    else if(a==b){
        if(a==0)printf("0\n");
        else printf("1\n");
    }
    else{
        printf("2\n");
    }
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
*/