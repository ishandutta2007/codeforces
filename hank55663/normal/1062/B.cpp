
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
    map<int,int> m;
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        while(n%i==0){
            m[i]++;
            n/=i;
        }
    }
    int ans=1;
    int Max=0;
    for(auto it:m){
        ans*=it.x;
        for(int num=1,tot=1;num<it.y;num<<=1,tot++){
            Max=max(Max,tot);
        }
    }
    int add=0;
    for(auto it:m){
        if(it.y!=(1<<Max)){
            add=1;
            break;
        }
    }
    printf("%d %d\n",ans,Max+add);
}