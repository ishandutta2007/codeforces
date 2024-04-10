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
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[200005];
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    int Max=n,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int now=0,cnt=1;
        for(int j=mid;j<=n;j++){
            if(now+a[j]<=k){
                now+=a[j];
            }
            else{
                cnt++;
                now=a[j];
            }
        }
        if(cnt>m){
            Min=mid;
        }
        else{
            Max=mid;
        }
    }
    printf("%d\n",n-Max+1);
}