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
const int mod=1e9+7;
vector<int> prime;
int digit(int x){
    int cnt=0;
    while(x){
        cnt++;
        x/=10;
    }
    return cnt;
}
void solve(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int resc=1;
    for(int i = 1;i<c;i++)resc*=10;
    int resa=1;
    for(int i = 1;i<a;i++)resa*=10;
    int resb=1;
    for(int i = 1;i<b;i++)resb*=10;
    resa=(resa/resc+1)*resc;
    resb=(resb/resc+1)*resc;
    while(__gcd(resa,resb)!=resc){
        resb+=resc;
    }
    printf("%d %d\n",resa,resb);
    assert(digit(resa)==a&&digit(resb)==b);
}
int main(){
    int t=1;
    scanf("%d",&t);
    //for(int i = 2)
    while(t--){
        solve();
    }
}