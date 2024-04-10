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
#define index Index
#define MXN 1000000
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pll> v;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        int cnt=1;
        while(x%m==0){
            cnt*=m;
            x/=m;
        }
        if(v.size()&&v.back().x==x)v.back().y+=cnt;
        else v.pb(mp(x,cnt));
    }
    int k;
    scanf("%d",&k);
    vector<pll> v2;
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        int cnt=1;
        while(x%m==0){
            cnt*=m;
            x/=m;
        }
        if(v2.size()&&v2.back().x==x)v2.back().y+=cnt;
        else v2.pb(mp(x,cnt));
    }
    if(v==v2)printf("Yes\n");
    else printf("No\n");

}
int main(){
 //   srand(time(NULL));
    int t=1;00000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}