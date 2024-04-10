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
    int n,k;
    scanf("%d %d",&n,&k);
    map<char,int> m;
    char c[200005];
    scanf("%s",c);
    int sum=1;
    for(int i=1;c[i]!=0;i++){
        if(c[i]==c[i-1]){
            sum++;
        }
        else{
            m[c[i-1]]+=sum/k;
            sum=1;
        }
    }
    m[c[strlen(c)-1]]+=sum/k;
    int Max=0;
    for(auto it:m)
    Max=max(Max,it.y);
    printf("%d\n",Max);
}