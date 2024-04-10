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
    vector<int> zero;
    vector<pii> nega;
    int vis[200005];
    fill(vis,vis+n+1,0);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        if(a<0)
        nega.pb(mp(a,i));
        if(a==0)
        zero.pb(i);
    }
    if(zero.size()==n-1&&nega.size()==1){
        for(int i=1;i<n;i++){
            printf("1 %d %d\n",i,i+1);
        }
    }
    else if(zero.size()==n){
        for(int i=1;i<n;i++){
            printf("1 %d %d\n",i,i+1);
        }
    }
    else{
        for(int i=0;i<(int)zero.size()-1;i++){
            printf("1 %d %d\n",zero[i],zero[i+1]);
            vis[zero[i]]=1;
        }
        if(nega.size()&1){
            sort(nega.begin(),nega.end());
          //  printf("?\n");
            if(zero.size())
            printf("1 %d %d\n",nega.back().y,zero.back());
            else
            printf("2 %d\n",nega.back().y);
            vis[nega.back().y]=1;
        }
        if(zero.size()){
            printf("2 %d\n",zero.back());
            vis[zero.back()]=1;
        }
        int last=-1;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(last!=-1)
                printf("1 %d %d\n",last,i);
                last=i;
            }
        }
    }
}