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
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
int main(){
    int n;
    scanf("%d",&n);
    int odd[500005];
    int even[500005];
    odd[0]=even[0]=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        odd[i]=odd[i-1];
        even[i]=even[i-1];
        if(i%2==0)
        even[i]+=x;
        else
        odd[i]+=x;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(odd[i-1]+even[n]-even[i]==even[i-1]+odd[n]-odd[i])
        cnt++;
    }
    printf("%lld\n",cnt);
}