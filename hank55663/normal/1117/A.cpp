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
    int n;
    scanf("%d",&n);
    int a[100005];
    int Max=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        Max=max(Max,a[i]);
    }
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==Max)cnt++;
        else{
            ans=max(ans,cnt);
            cnt=0;
        }
    }
    ans=max(ans,cnt);
    printf("%d\n",ans);
}
/*

i f f x f l b
*/