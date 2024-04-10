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
    int n,k;
    scanf("%d %d",&n,&k);
    LL ans=0;
    int a[200005];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    char c[200005];
    scanf("%s",c);
    vector<int> v;
    v.pb(a[0]);
    for(int i=1;i<n;i++){
        if(c[i]!=c[i-1]){
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            for(int i=0;i<k&&i<v.size();i++){
                ans+=v[i];
            }
          //  printf("%lld\n",ans);
            v.clear();
            v.pb(a[i]);
        }
        else{
            v.pb(a[i]);
        }
    }
     sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            for(int i=0;i<k&&i<v.size();i++){
                ans+=v[i];
            }
    printf("%lld\n",ans);
}