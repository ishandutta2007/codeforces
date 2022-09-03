#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
#define MXN 3000
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<pii> v;
    for(int i = 0;i<n;i++){
        int t=1e6,b=1e6;
        scanf("%d %d",&t,&b);
        v.pb(mp(b,t));
    }
    sort(v.begin(),v.end());
    multiset<int> s1,s2;
    for(auto it:v)
    s2.insert(-it.y);
    LL sum = 0;
    for(int i = 0;i<k;i++){
        s1.insert(*s2.begin());
        sum-=*s2.begin();
        s2.erase(s2.begin());
    }
    LL ans=0;
    for(int i = 0;i<n;i++){
        ans=max(ans,sum*v[i].x);
        if(s2.find(-v[i].y)!=s2.end()){
            s2.erase(s2.find(-v[i].y));
        }
        else{
            s1.erase(s1.find(-v[i].y));
            sum-=v[i].y;
            if(s2.size()){
                s1.insert(*s2.begin());
                sum-=*s2.begin();
                s2.erase(s2.begin());
            }
        }
    }
    printf("%lld\n",ans);
}