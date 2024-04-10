#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
LL a[30][30];
map<LL,int> dp[30][30];
int n,m;
LL k;
void dfs(int x,int y,int step,LL sum){
    if(x==n)
        return;
    if(y==m)
        return ;
    if(step==0){
        dp[x][y][sum]++;
        return ;
    }
    dfs(x+1,y,step-1,sum^a[x][y]);
    dfs(x,y+1,step-1,sum^a[x][y]);
}
LL ans=0;
void dfs2(int x,int y,int step,LL sum){
    if(x==-1)
    return;
    if(y==-1)
    return;
    if(step==0){
        ans+=dp[x][y][k^sum^a[x][y]];
        return ;
    }
    dfs2(x-1,y,step-1,sum^a[x][y]);
    dfs2(x,y-1,step-1,sum^a[x][y]);
}
int main(){
    scanf("%d %d %lld",&n,&m,&k);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%lld",&a[i][j]);
    dfs(0,0,(n-1+m-1)/2,0);
    dfs2(n-1,m-1,(n-1+m-1)-(n-1+m-1)/2,0);
    printf("%lld\n",ans);
}

/*int main(){
    vector<int> in,out;
    int n,m;
    scanf("%d %d",&n,&m);
    out.pb(0);
    in.pb(n+1);
    vector<int> ss;
    pii p[300005];
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        p[i]=mp(a,b);
        ss.pb(b+1);
        ss.pb(a);
    }
    sort(p,p+m);
    p[m]=mp(1e9,1e9);
    sort(ss.begin(),ss.end());
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    multiset<int> s;
    LL ans=0;
    int last=-100;
    int now=0;
    int lll=-100;
    for(int i=0;i<ss.size()-1;i++){
       
        int it=ss[i];
        if(it==n+1)
        break;
        while(!pq.empty()&&pq.top().x<it){
            pii p=pq.top();
            pq.pop();
            s.erase(s.find(p.y));
        }
        //printf("%d\n",it);
        while(p[now].x==it){
            pq.push(mp(p[now].y,p[now].x));
            s.insert(p[now].x);
            now++;
        }
        LL num=ss[i+1]-ss[i];
           // printf("%lld\n",num);
           // printf("%d %d %d %d\n",*iit,*in.upper_bound(last),last,in.upper_bound(last)==in.end());
            ans +=num*(pq.top().x-*s.rbegin()+1);
     //   printf("%d %d\n",it,ans);
    }
    printf("%lld\n",ans);
}*/