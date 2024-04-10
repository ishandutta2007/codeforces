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
int vis[100005];
int l[100005];
int r[100005];
int cnt[100005];
int Find(int x,int *f){
    if(f[x]==x)return x;
    return f[x]=Find(f[x],f);
}
int main(){
    map<int,vector<int> > m;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        m[x].pb(i);
        l[i]=i;
        r[i]=i;
    }
    int Max=0,ans=0;
    int tot=0;
    for(auto it:m){
        int last;
        for(auto it2:it.y){
            tot++;
            vis[it2]=1;
            if(vis[it2-1]){
                int Size=Find(it2-1,r)-Find(it2-1,l)+1;
                cnt[Size]--;
                l[it2]=Find(it2-1,l);
                r[Find(it2-1,r)]=it2;
            }
            if(vis[it2+1]){
                int Size=Find(it2+1,r)-Find(it2+1,l)+1;
                cnt[Size]--;
                l[Find(it2+1,l)]=Find(it2,l);
                r[Find(it2,r)]=Find(it2+1,r);
            }
            int Size=Find(it2,r)-Find(it2,l)+1;
            cnt[Size]++;
            last=Size;
        }
        if(last*cnt[last]==tot){
         //   printf("%d %d %d\n",it.x,last,cnt[last]);
            if(Max<cnt[last]){
                ans=it.x+1;
                Max=cnt[last];
            }
        }
    }
    printf("%d\n",ans);
}