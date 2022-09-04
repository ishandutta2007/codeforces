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
using namespace std;
void solve(){
    int x;
    scanf("%d",&x);
    if(x==2){
        printf("3\n");
        return;
    }
    LL Max=x,Min=0;
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        LL val=(1+mid)*mid/2;
        if(val==x){
            printf("%lld\n",mid);
            return;
        }
        if(val>x+1){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    printf("%lld\n",Max);
}
int main(){
    int t=1;
    scanf("%d",&t);
    //int n;
    while(t--){
        solve();
    }
}