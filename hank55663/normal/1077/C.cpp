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
    scanf("%d",&n);
    int a[500005];
    LL sum=0;
    multiset<int> s;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        s.insert(a[i]);
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        s.erase(s.find(a[i]));
        LL need=sum-a[i];
        if(*s.rbegin()*2==need){
            ans.pb(i+1);
        }
        s.insert(a[i]);
    }
    printf("%d\n",ans.size());
    for(auto it:ans)
    printf("%d ",it);
}