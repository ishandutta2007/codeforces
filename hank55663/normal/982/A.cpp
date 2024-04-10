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
    int n;
    scanf("%d",&n);
    char c[1005];
    scanf("%s",c+1);
        c[0]='0',c[n+1]='0';
    for(int i=1;i<=n;i++){
        if(c[i]=='1'){
            if(c[i-1]=='1'||c[i+1]=='1'){
                printf("NO\n");
                return 0;
            }
        }
        else{
            if(c[i-1]=='0'&&c[i+1]=='0'){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}