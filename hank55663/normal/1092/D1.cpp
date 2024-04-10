
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    if(n==1){
        printf("YES\n");
        return 0;
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        int num=a[i]&1;
        if(!v.empty()&&v.back()==num)v.pop_back();
        else v.pb(num);
    }
    if(v.size()<=1)
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}