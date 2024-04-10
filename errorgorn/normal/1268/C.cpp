#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>,
rb_tree_tag, tree_order_statistics_node_update>
indexed_set;

struct node{
  int s,e,m,len;
  long long v,lazy;
  node *l,*r;
  node(int _s,int _e){
    s=_s,e=_e,m=(s+e)>>1,lazy=0,len=e-s+1;
    if (s==e){
      v=0; //here the value of all points is 0 at first
    }
    else{
      l=new node(s,m);
      r=new node(m+1,e);
      v=(l->v)+(r->v); //edit this for diff
    }
  }
  long long lazy_add(){
    v+=lazy*len;
    if (s!=e) (l->lazy)+=lazy,(r->lazy)+=lazy; //edit this for diff
    lazy=0;
    return v;
  }
  long long query(int i,int j){
    lazy_add();
    if (i==s && j==e) return v;
    else if (j<=m) return l->query(i,j);
    else if (m<i) return r->query(i,j);
    else return l->query(i,m)+r->query(m+1,j);//edit this for diff

  }
  void update(int i,int j, long long k){
    if (i==s && j==e){
      lazy+=k;
      return;
    }
    else if (j<=m) l->update(i,j,k);
    else if (m<i) r->update(i,j,k);
    else l->update(i,m,k),r->update(m+1,j,k);
    v=(l->lazy_add())+(r->lazy_add());//edit this for diff
  }
}*root=new node(0,200005);


int n;
int arr[200005];
int pos[200005];

int fen[200005];
void update(int i,int j){
    while (i<=200005){
        fen[i]+=j;
        i+=i&-i;
    }
}

int query(int i){
    int res=0;
    while (i){
        res+=fen[i];
        i-=i&-i;
    }
    return res;
}

indexed_set s;

long long ans[200005];
int main(){
    scanf("%d",&n);
    for (int x=1;x<=n;x++){
        scanf("%d",&arr[x]);
        pos[arr[x]]=x;
    }
    
    for (int x=1;x<=n;x++){
        update(pos[x],1);
        ans[x]=ans[x-1]+x-query(pos[x]);
    }
    
    memset(fen,0,sizeof(fen));
    
    long long curr=0;
    long long total=0;
    for (int x=1;x<=n;x++){
        s.insert(pos[x]);
        root->update(0,0,pos[x]);
        root->update(1,pos[x],-1);
        root->update(pos[x]+1,200005,1);
        ans[x]+=root->query(0,*s.find_by_order(x>>1));
        ans[x]-=total;
        if (x&1) curr++;
        total+=curr;
    }
    
    for (int x=1;x<=n;x++) printf("%lld ",ans[x]);
}