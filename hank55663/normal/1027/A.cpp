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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[105];
        int n;
        scanf("%d",&n);
        scanf("%s",c);
        int l=0,r=strlen(c)-1;
        int ok=1;
        for(;l<r;l++,r--){
            if(abs(c[l]-c[r])!=2&&c[l]!=c[r]){
                printf("NO\n");
                ok=0;
                break;
            }
        } 
        if(ok){
            printf("YES\n");
        }
    }
}