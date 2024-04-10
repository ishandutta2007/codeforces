#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
vector<int> v[150005];
int Size[150005];
int forbid[150005];
int val[150005];
vector<int> stk;
void dfs(int x,int f){
    Size[x]=1;
    stk.pb(x);
    for(auto it:v[x]){
        if(it!=f&&!forbid[it]){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
}
bool cmp(const int &a,const int &b){
    return Size[a]<Size[b];
}
int find_cen(int x){
    stk.clear();
    dfs(x,0);
    sort(stk.begin(),stk.end(),cmp);
    for(auto it:stk){
        if(Size[it]>=Size[x]/2){
            return it;
        }
    }
}
LL ans;
vector<pll> vv;
void dfs2(int x,int f,LL sum,LL sum2,LL len){
    sum+=val[x];
    sum2+=sum;
  //  printf("%d %d %d\n",x,sum,sum2);
    vv.pb(mp(len,sum2));
    for(auto it:v[x]){
        if(it!=f&&!forbid[it]){
            dfs2(it,x,sum,sum2,len+1);
        }
    }
}
void dfs3(int x,int f,LL sum,LL sum2,LL len){
    sum+=val[x];
    sum2+=val[x]*len;
    vv.pb(mp(sum,sum2));
    for(auto it:v[x]){
        if(it!=f&&!forbid[it]){
            dfs3(it,x,sum,sum2,len+1);
        }
    }
}
struct DATA{
    LL x,y,st;
};
int op;
bool operator<(const DATA &p,const DATA &q){
    if(op==0)return p.x<q.x;
    else return p.st<q.st;
}
void go(int x){
    int cen=find_cen(x);
//    printf("cen:%d\n",cen);
    set<DATA> s;
  //  printf("%d\n",cen);
    for(int t=0;t<2;t++){
         s.insert({0,0,-1000000000});
        for(auto x:v[cen]){
            //ans=max(ans,)
            if(forbid[x])continue;
            dfs2(x,cen,val[cen],val[cen],2);
            op=1;
            for(auto p:vv){
               // if(s.empty())break;
              // printf("%d %d\n",p.x,p.y);
                auto it=prev(s.upper_bound({0,0,p.x}));
               // printf("query %d %d\n",p.x,p.y);
               // printf("%d %d\n",it->x,it->y);
                ans=max(ans,p.x*it->x+it->y+p.y);
            }
            vv.clear();
            dfs3(x,cen,0,0,1);
            op=0;
            for(auto p:vv){
              //  printf("add %d %d\n",p.x,p.y);
                auto it=s.lower_bound({p.x,p.y,0});
                if(it!=s.end()&&it->x==p.x){
                    if(it->y>p.y)continue;
                    else{
                        s.erase(*it);
                        it=s.lower_bound({p.x,p.y,0});
                    }
                }
                while(it!=s.end()){
                    DATA d=*it;
                    auto it2=next(it);
                    s.erase(it);
                    it=it2;
                    LL st=(p.y-d.y)/(d.x-p.x);
                    d.st=st;
                    if(it==s.end()||it->st>st){
                        s.insert(d);
                        break;
                    }
                }
                it=s.lower_bound({p.x,p.y,0});
                int st=-1e9;
                while(it!=s.begin()){
                    DATA d=*prev(it);
                    st=(d.y-p.y)/(p.x-d.x);
                    if(st<=d.st){
                        s.erase(d);
                    }
                    else{
                        break;
                    }
                }
                if(it==s.end()||it->st>st)s.insert({p.x,p.y,st});
             /*   for(auto it:s){
                    printf("%d %d %d\n",it.st,it.x,it.y);
                }*/
            }
            vv.clear();
        }
        op=1;
        auto it=prev(s.upper_bound({0,0,1}));
        ans=max(ans,it->x+it->y+val[cen]);
        reverse(v[cen].begin(),v[cen].end());
        s.clear();
    }
    forbid[cen]=1;
    for(auto it:v[cen]){
        if(!forbid[it]){
            go(it);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1;i<=n;i++)scanf("%d",&val[i]);
    go(1);
    printf("%lld\n",ans);
}