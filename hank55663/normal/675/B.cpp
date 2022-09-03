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
    int n,a,b,c,d;
    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    vector<int> v{a+b,a+c,c+d,b+d};
    sort(v.begin(),v.end());
    int l=v.back()+1-v[0];
    if(n<l)printf("0\n");
    else printf("%lld\n",(n-l+1ll)*n);
    return true;
}
int main(){
    int t=1;;//  scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}