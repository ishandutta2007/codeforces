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
bool cmp(const pii &a,const pii &b){
    if(a.x!=b.x)
    return a.x<b.x;
    else
    return a.y>b.y;
}
LL dis(const pii &a,const pii &b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
    int n;
    scanf("%d",&n);
    map<int,vector<pii> > v;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[max(x,y)].pb(mp(x,y));
    }
    pair<LL,pii> l,r;
    l=r=mp(0,mp(0,0));
    for(auto it:v){
        sort(it.y.begin(),it.y.end(),cmp);
        LL add=dis(it.y.back(),it.y.front());
        pair<LL,pii> templ=mp(add+min(l.x+dis(l.y,it.y.back()),r.x+dis(r.y,it.y.back())),it.y.front());
        pair<LL,pii> tempr=mp(add+min(l.x+dis(l.y,it.y.front()),r.x+dis(r.y,it.y.front())),it.y.back());
        l=templ;
        r=tempr;
      //  printf("%d %d\n",l.x,r.x);
      //  printf("%d\n",add);
    }
    printf("%lld\n",min(l.x,r.x));
}