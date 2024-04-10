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
    pii p[10005];
    p[0]=mp(0,0);
    LL tot=0;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        if(p[i]==p[i-1])
        continue;
        int Max=max(p[i-1].x,p[i-1].y);
        int Min=min(p[i].x,p[i].y);
       // printf("%d %d\n",Max,Min);
        if(p[i-1].x==p[i-1].y)
        tot+=max(Min-Max,0);
        else
        tot+=max(Min-Max+1,0);
    }
    printf("%d\n",tot+1);
}
/*

i f f x f l b
*/