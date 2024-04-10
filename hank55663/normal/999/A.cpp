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
    int n,k;
    scanf("%d %d",&n,&k);
    int a[105];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(int t=0;t<2;t++){
        for(int j=0;j<n;j++){
            if(a[j]>k)
            break;
            cnt++;
        }
        reverse(a,a+n);
    }
    printf("%d\n",min(cnt,n));
}