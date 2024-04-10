#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<int> v[300005];
vector<pii> bound[300005];
int p[300005];
int in[300005];
int out[300005];
int ti;
void dfs(int x,int f){
    in[x]=++ti;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            bound[x].pb(mp(ti,it));
        }
    }
    out[x]=ti;
}
struct node{
    node *l,*r;
    int a,b;
    int tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(0){

    }
}*root;
void build(node *n){
    if(n->a==n->b){
        n->tag=1e9;
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void revise(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r){
        return ;
    }
    push(n);
    revise(n->l,l,r,k);
    revise(n->r,l,r,k);
}
void Set(node *n,int x,int k){
    if(n->a==n->b){
        n->tag=k;
        return ;
    }
    push(n);
    if(x<=n->l->b)Set(n->l,x,k);
    else Set(n->r,x,k);
}
int query(node *n,int x){
    if(n->a==n->b){
        return n->tag;
    }
    push(n);
    if(x<=n->l->b)return query(n->l,x);
    else return query(n->r,x);
}
set<int> s;
int main(){
    int m;
    scanf("%d",&m);
    for(int i = 2;i<=m+1;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
        p[i]=x;
    }
    dfs(1,0);
    root = new node(1,m+1);
    build(root);
    Set(root,1,0);
    s.insert(1);
    pii mid=mp(1,1);
    for(int i = 2;i<=m+1;i++){
        int x=query(root,in[p[i]]);
      //  printf("%d %d\n",p[i],x);
        if(x==0){
            if(mid.x==mid.y){
                if(in[mid.x]<=in[i]&&out[mid.x]>=in[i]){
                    auto p=*lower_bound(bound[mid.x].begin(),bound[mid.x].end(),mp(in[i],0));
                    mid.y=p.y;
                    auto it=s.lower_bound(in[mid.y]);
                    while(it!=s.end()&&*it<=out[mid.y]){
                        auto it2=next(it);
                        s.erase(it);
                        it=it2;
                    }
                    s.insert(in[i]);
                    revise(root,in[mid.y],out[mid.y],1);
                    Set(root,in[i],0);
                }
                else{
                    while(!s.empty()&&*s.begin()<in[mid.x]){
                        s.erase(s.begin());
                    }
                    while(!s.empty()&&*s.rbegin()>out[mid.x]){
                        s.erase(*s.rbegin());
                    }
                    s.insert(in[i]);
                    revise(root,1,m+1,1);
                    revise(root,in[mid.x],out[mid.x],-1);
                    Set(root,in[i],0);
                    mid.x=p[mid.x];
                }
            }
            else{
                if(in[mid.y]<=in[i]&&out[mid.y]>=in[i]){
                    auto it=s.lower_bound(in[mid.y]);
                    while(it!=s.end()&&*it<=out[mid.y]){
                        auto it2=next(it);
                        s.erase(it);
                        it=it2;
                    }
                    s.insert(in[i]);
                    revise(root,in[mid.y],out[mid.y],1);
                    Set(root,in[i],0);
                    mid.x=mid.y;
                }
                else{
                    while(!s.empty()&&*s.begin()<in[mid.y]){
                        s.erase(s.begin());
                    }
                    while(!s.empty()&&*s.rbegin()>out[mid.y]){
                        s.erase(*s.rbegin());
                    }
                    s.insert(in[i]);
                    revise(root,1,m+1,1);
                    revise(root,in[mid.y],out[mid.y],-1);
                    Set(root,in[i],0);
                    mid.y=mid.x;
                }
            }
        }
        else{
            Set(root,in[i],x-1);
            if(x==1)
                s.insert(in[i]);
        }
     //   printf("%d %d %d %d\n",i,mid.x,mid.y,s.size());
     printf("%d\n",s.size());
    }
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/