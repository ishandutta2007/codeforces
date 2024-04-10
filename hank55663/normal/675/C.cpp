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
using namespace std;
bool solve(){
    map<LL,int> m;
    LL sum=0;
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int a;
        scanf("%d",&a);
        sum+=a;
        m[sum]++;
    }
    int Max=0;
    for(auto it:m)Max=max(Max,it.y);
    printf("%d\n",n-Max);
    return true;
}
int main(){
    int t=1;;//  scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}