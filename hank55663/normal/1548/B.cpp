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
void solve(){
    int n;
    scanf("%d",&n);
    LL a[200005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
       // a[i]=(1ll<<(i%60));
    }
    for(int i = n-1;i>0;i--){
        a[i]-=a[i-1];
        a[i]=abs(a[i]);
    }
    LL ans=1;
    vector<pll> v;
    for(int i = 1;i<n;i++){
        for(auto &it:v){
            it.x=__gcd(it.x,a[i]);
        }
        //printf("%d ",a[i]);
        v.pb(mp(a[i],i));
        sort(v.begin(),v.end());
        vector<pll> tmp;
        for(auto it:v){
            if(it.x!=1){
                ans=max(ans,i-it.y+2);
                if(tmp.size()&&tmp.back().x==it.x);//tmp.back().y=it.y;
                else tmp.pb(it);
            }
        }
        swap(v,tmp);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
*/