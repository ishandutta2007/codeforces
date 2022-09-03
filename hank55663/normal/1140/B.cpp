#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
#define MXN 3000
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char c[1005];
        scanf("%s",c);
        int ans=strlen(c);
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='>'){
                ans=min(ans,i);
                break;
            }
        }
        for(int i =strlen(c)-1;i>=0;i--){
            if(c[i]=='<'){
                ans=min(ans,(int)strlen(c)-1-i);
            }
        }
        printf("%d\n",ans);
    }
}