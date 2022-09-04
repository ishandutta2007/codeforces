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
vector<pii> v[1000005];
int dfs(int a,int f){
    for(auto &it:v[a]){
        if(it.y!=f){
            it.x=dfs(it.y,a);
        }
    }
    sort(v[a].begin(),v[a].end());
    reverse(v[a].begin(),v[a].end());
    return v[a][0].x+1;
}
int A[1000005];
pair<vector<int>*,int> dfs2(int a,int f){
    vector<int>* vec=NULL;
    int ans=-1;
   // printf("%d\n",a);
    for(auto it:v[a]){
        if(it.y!=f){
            if(vec==NULL){
                auto p =dfs2(it.y,a);
                vec=p.x;
                ans=p.y;
            }
            else{
                vector<int> *temp = dfs2(it.y,a).x;
                for(int i=0;i<temp->size();i++){
                    (*vec)[vec->size()-i-1]+=(*temp)[temp->size()-i-1];
                    if((*vec)[vec->size()-i-1]>(*vec)[ans]){
                        ans=vec->size()-i-1;
                    }
                    else if((*vec)[vec->size()-i-1]==(*vec)[ans]&&vec->size()-i-1>ans){
                        ans=vec->size()-i-1;
                    }
                }
                delete temp;
            }
        }
    }
    if(vec==NULL){
        vec=new vector<int>();
    }
    //printf("%d %d\n",ans,a);
    if(ans==-1||(*vec)[ans]==1){
        ans=vec->size();
    }
   // printf("%d %d\n",ans,a);
    A[a]=vec->size()-ans;
    vec->pb(1);
    return mp(vec,ans);
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("0\n");
        return 0;
    }
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].pb(mp(0,b));
        v[b].pb(mp(0,a));
    }
    dfs(1,0);
    //printf("?\n");
    auto p=dfs2(1,0);
    delete p.x;
    for(int i=1;i<=n;i++){
        printf("%d\n",A[i]);
    }
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