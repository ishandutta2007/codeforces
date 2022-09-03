#pragma GCC optimize("Ofast") 
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
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            m[x]++;
        }
        vector<int> v;
        for(auto it:m){
            if(it.y>=2)
            v.pb(it.x);
            if(it.y>=4)
            v.pb(it.x);
        }
        vector<int> ans;
        LL ansson=1e9,ansmon=1;
        for(int i=1;i<v.size();i++){
            LL tempson=(v[i]+v[i-1])*2;
            tempson=tempson*tempson;
            LL tempmon=v[i]*v[i-1];
            if(tempson*ansmon<tempmon*ansson){
                ansson=tempson;
                ansmon=tempmon;
                ans=vector<int>{v[i],v[i],v[i-1],v[i-1]};
            }
        }
        //printf("%lld %lld\n",ansson,ansmon);
        for(auto it:ans)
        printf("%d ",it);
        printf("\n");
    }
}