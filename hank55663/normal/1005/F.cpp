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
vector<pii> v[200005];
vector<int> ans[200005];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].pb(mp(b,i));
        v[b].pb(mp(a,i));
    }
    queue<int> q;
    int d[200005];
    MEMS(d);
    d[1]=0;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(d[it.x]==-1){
                d[it.x]=d[x]+1;
                q.push(it.x);
            }
            if(d[it.x]==d[x]+1){
                ans[it.x].pb(it.y);
            }
        }
    }
    long long tot=1;
    for(int i=2;i<=n;i++){
        tot*=ans[i].size();
        if(tot>=k)
        break;
    }
    if(tot<k)
    k=tot;
    printf("%d\n",k);
    for(int i=0;i<k;i++){
        int ok[200005];
        MEM(ok);
        int temp=i;
        for(int i=2;i<=n;i++){
            ok[ans[i][temp%ans[i].size()]]=1;
            temp/=ans[i].size();
        }
        if(temp!=0)
        break;
        for(int j=0;j<m;j++)
        printf("%d",ok[j]);
        printf("\n");
    }
}