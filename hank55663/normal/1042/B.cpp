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
    map<string,LL> m;
    m["A"]=m["B"]=m["C"]=m["AB"]=m["AC"]=m["BC"]=m["ABC"]=1e9;
    while(n--){
        int x;
        string s;
        cin>>x>>s;
        sort(s.begin(),s.end());
        m[s]=min(m[s],(LL)x);
    }
    m["A"]=min(m["A"],min(m["AB"],m["AC"]));
    m["B"]=min(m["B"],min(m["AB"],m["BC"]));
    m["C"]=min(m["C"],min(m["AC"],m["BC"]));
    LL ans=min(m["ABC"],min(m["A"]+m["B"]+m["C"],min(m["AB"]+m["C"],min(m["AC"]+m["B"],m["BC"]+m["A"]))));
    if(ans>3e7)
    printf("-1\n");
    else
    printf("%lld\n",ans);
}