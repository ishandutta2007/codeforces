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
int val[1000005];
pii p[1000005];
int type[1000005];
void dfs(int x){
    if(type[x]==0)
        return;
    else if(type[x]==4){
        dfs(p[x].x);
        val[x]=val[p[x].x]^1;
    }
    else{
        dfs(p[x].x);
        dfs(p[x].y);
        if(type[x]==1){
            val[x]=val[p[x].x]&val[p[x].y];
        }
        if(type[x]==2){
            val[x]=val[p[x].x]|val[p[x].y];
        }
        if(type[x]==3){
            val[x]=val[p[x].x]^val[p[x].y];
        }
    }
}
vector<int> *dfs2(int x){
    if(type[x]==0)
        return new vector<int>(1,x);
    if(type[x]==4){
        return dfs2(p[x].x);
    }
    if(type[x]==1){
        if(val[p[x].x]==0&&val[p[x].y]==0)
            return new vector<int>();
        if(val[p[x].x]==1&&val[p[x].y]==0)
            return dfs2(p[x].y);
        if(val[p[x].y]==1&&val[p[x].x]==0)
            return dfs2(p[x].x);
        vector<int>* v1=dfs2(p[x].x);
        vector<int>* v2=dfs2(p[x].y);
        if(v1->size()<v2->size())
        swap(v1,v2);
        for(auto it:*v2)
            v1->pb(it);
        return v1;
    }
    if(type[x]==2){
        if(val[p[x].x]==1&&val[p[x].y]==1)
            return new vector<int>();
        if(val[p[x].x]==1&&val[p[x].y]==0)
            return dfs2(p[x].x);
        if(val[p[x].y]==1&&val[p[x].x]==0)
            return dfs2(p[x].y);
        vector<int>* v1=dfs2(p[x].x);
        vector<int>* v2=dfs2(p[x].y);
        if(v1->size()<v2->size())
        swap(v1,v2);
        for(auto it:*v2)
            v1->pb(it);
        return v1;
    }
    if(type[x]==3){
        vector<int>* v1=dfs2(p[x].x);
        vector<int>* v2=dfs2(p[x].y);
        if(v1->size()<v2->size())
        swap(v1,v2);
        for(auto it:*v2)
            v1->pb(it);
        return v1;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int> need;
    for(int i=1;i<=n;i++){
        char c[5];
        scanf("%s",c);
        if(c[0]=='I'){
            type[i]=0;
            scanf("%d",&val[i]);
            need.pb(i);
        }
        if(c[0]=='A'||c[0]=='O'||c[0]=='X'){
            if(c[0]=='A')
                type[i]=1;
            else if(c[0]=='O')
                type[i]=2;
            else
                type[i]=3;
            int x,y;
            scanf("%d %d",&x,&y);
            p[i]=mp(x,y);
        }
        if(c[0]=='N'){
            type[i]=4;
            scanf("%d",&p[i].x);
        }
    }
    dfs(1);
    vector<int> *v = dfs2(1);
    sort(v->begin(),v->end());
    auto it = v->begin();
    for(auto x:need){
        if(it!=v->end()&&*it==x){
            printf("%d",val[1]^1);
            it++;
        }
        else{
            printf("%d",val[1]);
        }
    }
    printf("\n");
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