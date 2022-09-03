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
    int n,l,w;
    scanf("%d %d %d",&n,&l,&w);
    vector<int> posn,posp,negn,negp;
    pii special=mp(-1e9,0);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a>=0){
            if(b>=0)
            posp.pb(a);
            if(b<0)
            posn.pb(a);
        }
        else if(a>-l){
            special=mp(a,b);
        }
        else{
            if(b>=0)
            negp.pb(-a-l);
            if(b<0)
            negn.pb(-a-l);
        }
    }
    sort(posn.begin(),posn.end());
    sort(negp.begin(),negp.end());
    LL ans=(LL)posn.size()*negp.size();
   // printf("%lld\n",ans);
    if(w!=1){
        for(auto it:posp){
            int need=it*2/(w-1)-l+it;
           // printf("%d\n",need);
            ans+=posn.end()-upper_bound(posn.begin(),posn.end(),need);
        }
        for(auto it:negn){
            int need=it*2/(w-1)-l+it;
            ans+=negp.end()-upper_bound(negp.begin(),negp.end(),need);
        }
    }
    //printf("%lld\n",ans);
    if(special.y!=0){
        if(special.y==-1){
            ans+=negp.size();
        }
        else{
            ans+=posn.size();
        }
    }
    printf("%lld\n",ans);
}