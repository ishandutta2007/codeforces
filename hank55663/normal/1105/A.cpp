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
int main(){
    int n;
    scanf("%d",&n);
    int a[1005];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=1e9,anst;
    for(int t=1;t<=100;t++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=max(abs(a[j]-t)-1,0);
        }
        if(sum<ans)
        ans=sum,anst=t;
    }
    printf("%d %d\n",anst,ans);
}