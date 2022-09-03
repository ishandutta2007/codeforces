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
void solve(){
    int n;
    scanf("%d",&n);
    LL sum=1;
    for(int i = 1;i<=n;i++){
        if(__gcd(i,n)==1){
            sum*=i;
            sum%=n;
        }
    }
    vector<int> v;
    for(int i = 1;i<=n;i++){
        if(__gcd(i,n)==1){
            if(i==1||sum!=i)v.pb(i);
        }
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d ",it);
    }
    printf("\n");
}
int main(){
    int t=1;00000;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/