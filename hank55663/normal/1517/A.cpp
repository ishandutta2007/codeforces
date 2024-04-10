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
#define MAXK 2500
void solve(){
    LL x;
    scanf("%lld",&x);
    if(x%2050!=0)printf("-1\n");
    else{
        LL sum=0;
        LL tot=x/2050;
        while(tot){
            sum+=tot%10;
            tot/=10;
        }
        printf("%lld\n",sum);
    }   
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/