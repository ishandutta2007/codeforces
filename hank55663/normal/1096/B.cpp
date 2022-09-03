
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
int mod=998244353;
int main(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c+1);
    int l=1,r=n;
    while(c[l]==c[1])l++;
    while(c[r]==c[n])r--;
    if(c[1]!=c[n]){
        printf("%d\n",l+n-r);
    }
    else{
        printf("%lld\n",(LL)l*(n-r+1)%mod);
    }
}