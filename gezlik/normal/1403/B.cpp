#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,cq,a[N+9];

void into(){
  scanf("%d%d",&n,&cq);
  for (int i=1;i<=n;++i)
    scanf("%d",&a[i]);
}

struct answer{
  
  struct tree{
    LL sum,add;
  }tr[N*4+9];
  
  void Pushup(int k){tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;}
  void Update_add(int k,int l,int r,LL v){tr[k].sum+=v*(r-l+1);tr[k].add+=v;}
  
  void Pushdown(int k,int l,int r){
    if (!tr[k].add) return;
    int mid=l+r>>1;
    Update_add(k<<1,l,mid,tr[k].add);
    Update_add(k<<1|1,mid+1,r,tr[k].add);
    tr[k].add=0;
  }
  
  void Change_add(int L,int R,LL v,int l,int r,int k){
    if (L>R) return;
    if (R<l) return;
    if (L>r) return;
    if (L<=l&&R>=r) {Update_add(k,l,r,v);return;}
    int mid=l+r>>1;
    Pushdown(k,l,r);
    if (L<=mid) Change_add(L,R,v,l,mid,k<<1);
    if (R>mid) Change_add(L,R,v,mid+1,r,k<<1|1);
    Pushup(k);
  }
  
  LL Query_sum(int L,int R,int l,int r,int k){
    if (L<=l&&R>=r) return tr[k].sum;
    int mid=l+r>>1;
    LL res=0;
    Pushdown(k,l,r);
    if (L<=mid) res+=Query_sum(L,R,l,mid,k<<1);
    if (R>mid) res+=Query_sum(L,R,mid+1,r,k<<1|1);
    return res;
  }
  
  void Add(int l,int r,int v){
    int len=r-l+1;
    int x=n-l+1,y=r,p=min(x,y),q=max(x,y);
    Change_add(len,len,v*(l-r+len-1),0,n,1);
    Change_add(p+1,p+1,-v*(l-r+len-1),0,n,1);
    Change_add(len,p,v,0,n,1);
    Change_add(p+1,p+1,-v*(p-len+1),0,n,1);
    if (p==x){
      Change_add(p+1,p+1,v*(n-r+1),0,n,1);
      Change_add(q+1,q+1,-v*(n-r+1),0,n,1);
    }else{
      Change_add(p+1,p+1,v*l,0,n,1);
      Change_add(q+1,q+1,-v*l,0,n,1);
    }
    Change_add(q+1,q+1,v*(n+1-q),0,n,1);
    Change_add(q+1,n,-v,0,n,1);
  }
  
  LL Query(int p){return Query_sum(0,p,0,n,1);}
  
}ans;

struct seg{
  int l,r,x;
  seg(int L=0,int R=0,int X=0){l=L;r=R;x=X;}
  bool operator < (const seg &p)const{return l<p.l;}
};
map<int,set<seg> >mp;
set<seg>s;

void Get_ans(){
  map<int,int>last;
  for (int i=1;i<=n;++i){
    mp[a[i]].insert(seg(i,i,a[i]));
    s.insert(seg(i,i,a[i]));
    int p=last[a[i]];
    if (p) ans.Add(p,i,1);
    last[a[i]]=i;
  }
}

void work(){
  Get_ans();
}

void Change(int l,int r,int c){
  seg p=*--s.upper_bound(seg(l));
  if (p.l<l){
    s.erase(p);
    mp[p.x].erase(p);
    s.insert(seg(p.l,l-1,p.x));
    mp[p.x].insert(seg(p.l,l-1,p.x));
    s.insert(seg(l,p.r,p.x));
    mp[p.x].insert(seg(l,p.r,p.x));
  }
  p=*--s.upper_bound(seg(r));
  if (r<p.r){
    s.erase(p);
    mp[p.x].erase(p);
    s.insert(seg(p.l,r,p.x));
    mp[p.x].insert(seg(p.l,r,p.x));
    s.insert(seg(r+1,p.r,p.x));
    mp[p.x].insert(seg(r+1,p.r,p.x));
  }
  vector<seg>tmp;
  set<int>col;
  for (set<seg>::iterator it=s.find(seg(l));it!=s.end()&&it->r<=r;++it){
    tmp.push_back(*it);
    col.insert(it->x);
    set<seg>&ss=mp[it->x];
    if (ss.find(*it)!=ss.begin()) ans.Add((--ss.find(*it))->r,it->l,-1);
    if (ss.find(*it)!=--ss.end()&&(++ss.find(*it))->l>r) ans.Add(it->r,(++ss.find(*it))->l,-1);
  }
  for (int vs=tmp.size(),i=0;i<vs;++i){
    s.erase(tmp[i]);
    mp[tmp[i].x].erase(tmp[i]);
    if (i) ans.Add(tmp[i-1].r,tmp[i].l,1);
  }
  if (col.find(c)!=col.end()) col.erase(c);
  else{
    set<seg>&ss=mp[c];
    set<seg>::iterator t=ss.lower_bound(l);
    if (t==ss.begin()||t==ss.end());
    else{
      int v=t->l,u=(--t)->r;
      ans.Add(u,v,-1);
    }
  }
  for (set<int>::iterator it=col.begin();it!=col.end();++it){
    int x=*it;
    set<seg>&ss=mp[x];
    set<seg>::iterator t=ss.lower_bound(l);
    if (t==ss.begin()||t==ss.end()) continue;
    int v=t->l,u=(--t)->r;
    ans.Add(u,v,1);
  }
  s.insert(seg(l,r,c));
  set<seg>::iterator it=(mp[c].insert(seg(l,r,c))).first;
  set<seg>&ss=mp[c];
  if (it!=ss.begin()){
    set<seg>::iterator p=it;--p;
    ans.Add(p->r,it->l,1);
  }
  if (it!=--ss.end()){
    set<seg>::iterator p=it;++p;
    ans.Add(it->r,p->l,1);
  }
}

void outo(){
  for (;cq--;){
    int opt;
    scanf("%d",&opt);
    if (opt==1){
      int l,r,x;
      scanf("%d%d%d",&l,&r,&x);
      Change(l,r,x);
    }else{
      int x;
      scanf("%d",&x);
      printf("%lld\n",1LL*x*(n-x+1)-ans.Query(x));
    }
  }
}

int main(){
  into();
  work();
  outo();
  return 0;
}