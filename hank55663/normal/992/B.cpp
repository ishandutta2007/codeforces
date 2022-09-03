#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
int main(){
    int l,r,x,y;
    scanf("%d %d %d %d",&l,&r,&x,&y);
    vector<int> fx,fy;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            fx.pb(i);
            if(i*i!=x){
                fx.pb(x/i);
            }
        }
    }
    for(int i=1;i*i<=y;i++){
        if(y%i==0){
            fy.pb(i);
            if(i*i!=y){
                fy.pb(y/i);
            }
        }
    }
    sort(fx.begin(),fx.end());
    sort(fy.begin(),fy.end());
    int ans=0;
    set<int> s;
    for(auto it:fx){
        for(auto it2:fy){
            LL a=(LL)it*it2,b=(LL)x*y/a;
            if(a>r)
            break;
            if(s.find(a)!=s.end())
            continue;
            s.insert(a);
            if(a>=l&&a<=r&&b>=l&&b<=r&&__gcd(a,b)==x){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}