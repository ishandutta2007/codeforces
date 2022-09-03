#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 3000000

int f[55],d[6];
int orid[6];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<pii> ntree[55];
vector<int> v[1005];
bool dfs(int x,int y,int f,int i,int d=0){
    assert(d<=100);
    if(x==y)return true;
    for(auto it:ntree[x]){
        if(it.x!=f){
            if(dfs(it.x,y,x,i,d+1)){
                if(it.y!=-1)
                v[it.y].pb(i);
                return true;
            }
        }
    }
    return false;
}
pii dis[1005];
int inq[1005];
int from[1005];
int val;
int cal(vector<pair<pii,int> > edge,vector<pii> tedge,int k,int n){
    vector<int> belong(edge.size(),0);
    for(auto it:edge){
        //printf("%d %d\n",it.x.x,it.x.y);
    }
    //for(int i = 1;i<=n;i++)f[i]=i;
   // printf("\n");
    int ans=0;
    while(true){
        vector<int> ok1(edge.size()),ok2(edge.size());
        for(int i = 1;i<=n;i++)ntree[i].clear();
        queue<int> q;
        for(auto it:tedge){
            ntree[it.x].pb(mp(it.y,-1));
            ntree[it.y].pb(mp(it.x,-1));
        }
        for(int i=0;i<edge.size();i++){
            dis[i]=mp(1e9,1e9);
            inq[i]=0;
            v[i].clear();
            from[i]=-1;
            ok1[i]=ok2[i]=0;
            if(belong[i]==0){
                if(f[Find(edge[i].x.x)]!=f[Find(edge[i].x.y)]){
                    dis[i]=mp(edge[i].y,0);
                    inq[i]=1;
                    q.push(i);
                    ok1[i]=1;
                }
                if(edge[i].x.x>k||d[edge[i].x.x]){
                    ok2[i]=1;
                }
            }
            else{
                ntree[edge[i].x.x].pb(mp(edge[i].x.y,i));
                ntree[edge[i].x.y].pb(mp(edge[i].x.x,i));
            }
       //     printf("%d%d ",ok1[i],ok2[i]);
        }
      //  printf("\n");
        for(int i = 0;i<edge.size();i++){
            for(int j = 0;j<edge.size();j++){
                if(belong[i]==1&&belong[j]==0){
                    if(ok2[j])v[j].pb(i);
                    else if(edge[i].x.x<=k){
                        if(edge[i].x.x==edge[j].x.x)v[j].pb(i);
                    }
                }
            }
            if(belong[i]==0){
                if(ok1[i]){
                    for(int j =0;j<edge.size();j++){
                        if(belong[j]==1)
                        v[j].pb(i);
                    }
                }
                else{
                    dfs(edge[i].x.x,edge[i].x.y,0,i);
                }
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            inq[x]=0;
            for(auto it:v[x]){
                pii p=dis[x];
                p.y++;
                if(belong[it]==0)p.x+=edge[it].y;
                else p.x-=edge[it].y;
                if(p<dis[it]){
                    dis[it]=p;
                    from[it]=x;
                    if(!inq[it]){
                        q.push(it);
                        inq[it]=1;
                    }
                }
            }
        }
        pii res=mp(1000000,1000000);
        int resi;
        for(int i = 0;i<edge.size();i++){
            if(ok2[i]){
                if(res>dis[i]){
                    res=dis[i];
                    resi=i;
                }
            }
        }
        if(res==mp(1000000,1000000)){
            for(int i=0;i<edge.size();i++){
                if(belong[i]==1){
                 //  printf("%d %d\n",edge[i].x.x,edge[i].x.y);
                }
            }
            if(val!=n-1)return 1e9;
            return ans;
        }
        val++;
        ans+=res.x;
        if(edge[resi].x.x<=k)
        d[edge[resi].x.x]--;
        while(from[resi]!=-1){
            belong[resi]^=1;
            resi=from[resi];
        }
        int a=edge[resi].x.x,b=edge[resi].x.y;
        assert(a!=b);
        f[Find(a)]=Find(b);
        belong[resi]^=1;
    }
}
int aa[55][55];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=k;i++){
        scanf("%d",&orid[i]);
    }
    for(int i = 1;i<=n;i++)f[i]=i;
    vector<pair<int,pii> > e;
    vector<pair<pii,int> > edge;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
             scanf("%d",&aa[i][j]);
           // aa[i][j]=rand()%100;
            if(i<=k&&j<=k){

            }
            else if(i>k&&j>k){
                e.pb(mp(aa[i][j],mp(i,j)));
            }
            else{
                edge.pb(mp(mp(i,j),aa[i][j]));
            }
        }
    }
    sort(e.begin(),e.end());
    for(auto it:e){
        int a=Find(it.y.x),b=Find(it.y.y);
        if(a!=b){
            edge.pb(mp(it.y,it.x));
            f[a]=b;
        }
    }
    for(int j = 1;j<=n;j++)f[j]=j;
    if(k==1){
        d[1]=orid[1];
        val=0;
        int res=cal(edge,vector<pii>(),1,n);
        printf("%d\n",res);
        return;
    }
    vector<pii> edgeset;
    for(int i = 1;i<=k;i++){
        for(int j = i+1;j<=k;j++){
            edgeset.pb(mp(i,j));
        }
    }
    int res=1e9;
   // printf("%d\n",edgeset.size());
    for(int i = 0;i<(1<<edgeset.size());i++){
        for(int j=1;j<=n;j++)f[j]=j;
        for(int j = 1;j<=k;j++)d[j]=orid[j];
        vector<pii> tree;
        int sum=0;
        int ok=1;
        val=0;
        for(int j = 0;j<edgeset.size();j++){
            if(i&(1<<j)){
                val++;
                sum+=aa[edgeset[j].x][edgeset[j].y];
                tree.pb(edgeset[j]);
                if(--d[edgeset[j].x]<0)ok=0;
                if(--d[edgeset[j].y]<0)ok=0;
                int a=Find(edgeset[j].x),b=Find(edgeset[j].y);
                if(a==b)ok=0;
                else f[a]=b;
            }
        }
        if(ok){
           // for(auto it:tree)printf("%d %d\n",it.x,it.y);
           int rres=cal(edge,tree,k,n);
            res=min(res,sum+rres);
           //  printf("%d\n",sum+rres);
             //if(rres+sum==93){
            ////     assert(0);
            // }
        }
    }
    printf("%d\n",res);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
*/