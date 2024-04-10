/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>*/
#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0) 
struct node{
    node *l,*r;
    int sum;
    int tag;
    int a,b;
    node(int _a,int _b){
        a=_a;
        b=_b;
        l=NULL;
        r=NULL;
        sum=0;
        tag=0;
    }
}*root;
int Sum(node *n){
    return n->tag?0:n->sum;
}
void pull(node *n){
    n->sum=Sum(n->l)+Sum(n->r);
}
void build(node *n=root){
    if(n->a==n->b){
        n->sum=1;
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int l,int r,int add){
    if(l>r)
    return;
    if(n->a>=l&&n->b<=r){
        n->tag+=add;
        assert(n->tag>=0);
        return ;
    }
    if(n->a>r||n->b<l){
        return ;
    }
    revise(n->l,l,r,add);
    revise(n->r,l,r,add);
    pull(n);
}
vector<int> vv[200005];
int in[200005];
int out[200005];
int t;
void dfs(int x,int f){
    in[x]=++t;
    for(int i=0;i<vv[x].size();i++){
        if(vv[x][i]==f){
            swap(vv[x][i],vv[x][vv[x].size()-1]);
        }
    }/*
    printf("%d %d %d\n",x,f,vv[x].back());
    vv[x].pop_back();*/
    if(f!=0)
    vv[x].pop_back();
    for(auto it:vv[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    out[x]=t;
}
bool cmp(const int &a,const int &b){
    return in[a]<in[b];
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    root = new node(1,n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        vv[x].pb(y);
        vv[y].pb(x);
    }
    srand(time(NULL));
    dfs(3,0);
    build(root);
    set<pii> s;
    while(q--){
        int u,v;
        scanf("%d %d",&u,&v);
        if(u>v)
        swap(u,v);
        if(s.find(mp(u,v))==s.end()){
            if(in[u]<in[v]&&out[u]>=in[v]){
                int a=in[u],b=in[v],c=out[v],d=out[u];
                //printf("%d %d %d %d\n",a,b,c,d);
                int x=*(upper_bound(vv[u].begin(),vv[u].end(),v,cmp)-1);
               // printf("%d\n",x);
                a=in[x],d=out[x];
                b--,c++;
               // printf("%d %d %d %d\n",a,b,c,d);
                revise(root,a,b,1);
                revise(root,c,d,1);
            }
            else if(in[v]<in[u]&&out[v]>=in[u]){
                int a=in[v],b=in[u],c=out[u],d=out[v];
                int x=*(upper_bound(vv[v].begin(),vv[v].end(),u,cmp)-1);
                a=in[x],d=out[x];
                b--,c++;
                revise(root,a,b,1);
                revise(root,c,d,1);
            }
            else{
                int a=in[v],b=out[v],c=in[u],d=out[u];
                if(a>c){
                    swap(a,c);
                    swap(b,d);
                }
                a--;
                b++;
                c--;
                d++;
                revise(root,1,a,1);
                revise(root,b,c,1);
                revise(root,d,n,1);
            }
            s.insert(mp(u,v));
        }
        else{
            if(in[u]<in[v]&&out[u]>=in[v]){
                int a=in[u],b=in[v],c=out[v],d=out[u];
                int x=*(upper_bound(vv[u].begin(),vv[u].end(),v,cmp)-1);
                a=in[x],d=out[x];
                b--,c++;
                revise(root,a,b,-1);
                revise(root,c,d,-1);
            }
            else if(in[v]<in[u]&&out[v]>=in[u]){
                int a=in[v],b=in[u],c=out[u],d=out[v];
                int x=*(upper_bound(vv[v].begin(),vv[v].end(),u,cmp)-1);
                a=in[x],d=out[x];
                b--,c++;
                revise(root,a,b,-1);
                revise(root,c,d,-1);
            }
            else{
                int a=in[v],b=out[v],c=in[u],d=out[u];
                if(a>c){
                    swap(a,c);
                    swap(b,d);
                }
                a--;
                b++;
                c--;
                d++;
                revise(root,1,a,-1);
                revise(root,b,c,-1);
                revise(root,d,n,-1);
            }
            s.erase(mp(u,v));
        }
        printf("%d\n",Sum(root));
    }
}