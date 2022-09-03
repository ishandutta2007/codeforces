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
LL dp[100005][205];
struct env{
    int ti,d,w,type;
};
bool cmp(const env &a,const env &b){
    return a.ti<b.ti;
}
int main(){
    dp[0][0]=0;
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=1e18;
        }
    }
    dp[0][0]=0;
    vector<env> v;
    for(int i=0;i<k;i++){
        int s,t,d,w;
        scanf("%d %d %d %d",&s,&t,&d,&w);
        v.pb({s,d,w,1});
        v.pb({t+1,d,w,-1});
    }
    if(m>=n){
        printf("0\n");
        return 0;
    }
    sort(v.begin(),v.end(),cmp);
    multiset<pii> s;
    int index=0;
    for(int i=0;i<=n;i++){
        while(index!=v.size()&&v[index].ti==i){
            if(v[index].type==-1){
                s.erase(s.find(mp(v[index].w,v[index].d)));
            }
            else{
                s.insert(mp(v[index].w,v[index].d));
            }
            index++;
        }
        pii p=mp(0,i);
        if(s.size())p=*s.rbegin();
        for(int j=0;j<=m;j++){
            if(j!=0)
            dp[i][j]=min(dp[i][j],dp[i][j-1]);
            //printf("%lld ",dp[i][j]);
            dp[p.y+1][j]=min(dp[i][j]+p.x,dp[p.y+1][j]);
            dp[i+1][j+1]=min(dp[i][j],dp[i+1][j+1]);
        }
        //printf("\n");
    }
    assert(dp[n+1][m]!=1e18);
    printf("%lld\n",dp[n+1][m]);
}