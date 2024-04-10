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
#define hash Hash
#define LL long long
int main(){
    int n;
    map<int,int> m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        m[x]++;
    }
    map<int,int> s;
    for(auto it:m){
        s[it.y]++;
    }
    int ans=0;
    for(int i=1;i<=200000;i++){
        int now=i;
        int sum=0;
        vector<int> v;
        while(s.lower_bound(now)!=s.end()){
            v.pb(s.lower_bound(now)->x);
            if(--s.lower_bound(now)->y==0){
                s.erase(s.lower_bound(now));
            }
            sum+=now;
            now*=2;
        }
        ans=max(ans,sum);
        for(auto it:v)
        s[it]++;
    }
    printf("%d\n",ans);
}