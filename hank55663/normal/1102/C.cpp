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
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    int a[105];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    if(x>y){
        printf("%d\n",n);
    }
    else{
        sort(a,a+n);
        int cnt=0;
        for(int i=0;i<n;i+=2){
            if(a[i]<=x){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}