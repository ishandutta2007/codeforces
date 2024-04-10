#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;

inline int Rand() {
    return rand()*RAND_MAX+rand();
}

struct SplayNode {
    SplayNode(int _v = 0) : v(_v), l(NULL), r(NULL), p(NULL), size(1), inv(0), key(Rand()), val(0), sum(0), sw(0) {};
    SplayNode *l,*r,*p;
    int v,key,size,inv,val,sum,sw;
};

SplayNode * nodes[100005];
int prev[100005];

int Size(SplayNode * a) {
    return a ? a->size : 0;
}

void Push(SplayNode * a) {
    if (a&&a->inv) {
        if (a->l) a->l->inv^=1;
        if (a->r) a->r->inv^=1;
        a->inv=0; swap(a->l,a->r);
    }
    if (a&&a->sw) {
        if (a->l) a->l->sw^=1;
        if (a->r) a->r->sw^=1;
        a->val^=1; a->sw=0; a->sum=Size(a)-a->sum;
    }
}

int Sum(SplayNode * a) {
    if (a) Push(a);
    return a ? a->sum : 0;
}

void Update(SplayNode * a) {
    if (a) {
        Push(a);
        a->size=Size(a->l)+1+Size(a->r);
        a->sum=Sum(a->l)+a->val+Sum(a->r);
        if (a->l) a->l->p=a;
        if (a->r) a->r->p=a;
    }
}

void RotateLeft(SplayNode * x) {
    SplayNode * y=x->p,* par=y->p;
    if (par)
        if (par->l==y) par->l=x;
        else par->r=x;
    x->p=y->p; y->p=x;
    y->l=x->r; x->r=y;
    if (y->l!=NULL) y->l->p=y;
    Update(y); Update(x);
}

void RotateRight(SplayNode * y) {
    SplayNode * x=y->p,* par=x->p;
    if (par)
        if (par->l==x) par->l=y;
        else par->r=y;
    y->p=x->p; x->p=y;
    x->r=y->l; y->l=x;
    if (x->r!=NULL) x->r->p=x;
    Update(x); Update(y);
}

void Normalize(SplayNode * x) {
    if (x&&x->p) Normalize(x->p);
    Push(x);
}

void Splay(SplayNode * x) {
    Normalize(x);
    int Prev=prev[x->v];
    while(x->p!=NULL) {
        if (x->p->p==NULL) {
//          Push(x->p);
            Prev=prev[x->p->v];
            if (x->p->l==x) RotateLeft(x);
            else RotateRight(x);
        } else {
            SplayNode * y=x->p,* z=y->p;
//          Push(z); Push(y);
            if (z->p==NULL) Prev=prev[z->v];
            if (y->l==x) {
                if (z->l==y) {
                    RotateLeft(y);
                    RotateLeft(x);
                } else {
                    RotateLeft(x);
                    RotateRight(x);
                }
            } else {
                if (z->r==y) {
                    RotateRight(y);
                    RotateRight(x);
                } else {
                    RotateRight(x);
                    RotateLeft(x);
                }
            }
        }
    }
    prev[x->v]=Prev;
}

SplayNode * GetRoot(SplayNode * a) {
//  while(a->p!=NULL) a=a->p;
    Splay(a);
    return a;
}

SplayNode * FindK(SplayNode * root,int k) {
    if (Size(root)<=k||k<0) return NULL;
    while(true) {
        Push(root);
        if (Size(root->l)==k) return root;
        if (Size(root->l)<k) {
            k-=Size(root->l)+1;
            root=root->r;
        } else root=root->l;
    }
    Splay(root);
    return root;
}

int GetIndex(SplayNode * x) {
    Normalize(x);// Splay(x);
//  SplayNode *tmp=x;
    int ret=Size(x->l);
    while(x->p!=NULL) {
        if (x->p->r==x)
            ret+=Size(x->p->l)+1;
        x=x->p;
    }
//  int Prev=prev[GetRoot(tmp)->v]; prev[GetRoot(tmp)->v]=-1;
//  Splay(tmp); prev[tmp->v]=Prev;
//  if (Size(tmp->l)!=ret) puts("fail");
    return ret;
}

void Merge(SplayNode * & t,SplayNode * l,SplayNode * r) {
    if (!l||!r) {
        t=l ? l : r;
        return;
    }
    Push(l); Push(r);
    while(l->r!=NULL) {
        l=l->r;
        Push(l);
    }
    Splay(l);
    l->r=r; r->p=l; t=l;
    Update(t);
}

void Split(SplayNode * t,SplayNode * & l,SplayNode * & r,int key) {
    SplayNode * node=FindK(t,key-1);
    if (node!=NULL) {
        Splay(node);
        l=node; r=node->r;
        l->r=NULL;
        if (r) r->p=NULL;
        Update(l); Update(r);
    } else {
        if (key==0) l=NULL,r=t;
        else l=t,r=NULL;
    }
}

void Output(SplayNode * a,int lev = 0) {
    if (a) {
        Push(a);
//      if (lev==0) a=GetRoot(a);
        Output(a->r,lev+1);
        for(int i=0;i<lev;++i) printf("\t");
        printf("(%d,sum = %d)\n",a->v,a->sum);
        Output(a->l,lev+1);
    }
}

void Expose(int v) {
    SplayNode * node=GetRoot(nodes[v]),* root;
    int p;
    while((p=prev[node->v])!=-1) {
        root=GetRoot(nodes[p]);
        int Prev=prev[root->v];
        SplayNode * l,* r;
        Split(root,l,r,GetIndex(nodes[p])+1);
        if (r) prev[r->v]=p;
        Merge(node,l,node);
        prev[node->v]=Prev;
    }
//  int Prev=prev[GetRoot(nodes[v])->v];
    Splay(nodes[v]);// prev[nodes[v]->v]=Prev;
}

void MakeRoot(int v) {
    Expose(v);
    SplayNode * l, *r;
    Split(GetRoot(nodes[v]),l,r,GetIndex(nodes[v]));
    if (l) {
        l->inv^=1;
        prev[l->v]=v;
    }
    Splay(nodes[v]);
}

void Link(int a,int b) {
    MakeRoot(a);
    prev[GetRoot(nodes[a])->v]=b;
}

void Cut(int a,int b) {
    SplayNode * ta,* tb;
    if ((ta=GetRoot(nodes[a]))==(tb=GetRoot(nodes[b]))) {
        int Prev=prev[ta->v];
        if (GetIndex(nodes[a])>GetIndex(nodes[b])) swap(a,b);
        SplayNode * l,* r;
        Split(ta,l,r,GetIndex(nodes[a])+1);
        prev[r->v]=-1; prev[l->v]=Prev;
        
    } else prev[prev[ta->v]==b ? ta->v : tb->v]=-1;
}


vector <vector <int> > g;
int c[100005],csize,ok,what,N,n;
bool used[100005],in[100005];
SplayNode * nodes2[100005],* cycle;


void UpdateCycle(int a,int b) {
    int index=GetIndex(nodes2[a]),index2=GetIndex(nodes2[b]),l1=abs(index-index2),l2=Size(cycle)-l1;
    if (index2<index) swap(l1,l2);
    SplayNode * prev=FindK(cycle,(index+N-1)%N), * next=FindK(cycle,(index+1)%N);
    if (l1<l2||l1==l2&&next->v<prev->v) {
        SplayNode * l, * r;
        Split(cycle,l,r,index+1);
        Merge(cycle,r,l);
        Split(cycle,l,r,GetIndex(nodes2[b])+1);
        l->sw^=1;
        Merge(cycle,l,r);
    } else {
        SplayNode * l, * r;
        Split(cycle,l,r,index+1);
        Merge(cycle,r,l);
        Split(cycle,l,r,GetIndex(nodes2[b])+1);
        r->sw^=1;
        Merge(cycle,l,r);
    }
}

int A,B,need,SUM=0;

void Get(int a,int b) {
/*  if (in[b]) {
        B=b; need=true;
        return;
    }*/
    Expose(a);
    SplayNode * root=GetRoot(nodes[a]), * tb;
    int ind=b,ans=0;
    while(ind!=-1&&!in[ind]&&(tb=GetRoot(nodes[ind]))!=root) {
        int Prev=prev[tb->v];
        SplayNode * l, * r, *tmp=NULL;
        if (Prev==-1) Split(tb,tmp,tb,1);
        Split(tb,l,r,GetIndex(nodes[ind])+1);
        if (l) {
            l->sw^=1; SUM-=l->sum; SUM+=Size(l)-l->sum;
        }
        Merge(tb,l,r); if (tb) prev[tb->v]=Prev;
        if (Prev==-1) Merge(tb,tmp,tb);
        ind=Prev;
    }
    if (ind==-1||in[ind]) {
        B=ind==-1 ? tb->v : ind;
        need=true;
    } else {
        int Prev=prev[tb->v];
        SplayNode * l, * r, *tmp, * mid;
        if (GetIndex(nodes[a])>GetIndex(nodes[ind])) swap(a,ind);
        Split(tb,l,r,GetIndex(nodes[ind])+1);
        Split(l,l,mid,GetIndex(nodes[a])+1);
        if (mid) {
            mid->sw^=1; SUM-=mid->sum; SUM+=Size(mid)-mid->sum;
        }
        Merge(l,l,mid);
        Merge(tb,l,r);
        ind=Prev; prev[tb->v]=Prev;
    }
    Expose(b);
}

void dfs(int v,int par = -1) {
    used[v]=true;
    for(int i=0;i<g[v].size();++i)
        if (g[v][i]!=par) {
            if (used[g[v][i]]) ok=1,what=g[v][i];
            else {
                if (!ok) c[csize++]=g[v][i];
                dfs(g[v][i],v);
                if (ok) return;
                if (!ok) csize--;
            }
        }
}

void dfs2(int v,int par = -1) {
    for(int i=0;i<g[v].size();++i)
        if (g[v][i]!=par&&!in[g[v][i]]) {
            Link(g[v][i],v);
            dfs2(g[v][i],v);
        }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int m,a,b;
    scanf("%d%d",&n,&m);
    g.resize(n);
    for(int i=0;i<n;++i) {
        scanf("%d%d",&a,&b); --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<=n;++i) {
        nodes[i]=new SplayNode(i);
        prev[i]=-1;
    }
    c[csize++]=0; dfs(0);
    cycle=NULL;
    for(int i=csize-1;i>=0;--i) {
        nodes2[c[i]]=new SplayNode(c[i]);
        Merge(cycle,cycle,nodes2[c[i]]);
        in[c[i]]=true;
        if (c[i]==what) break;
    }
//  Output(cycle); cout << endl;
    for(int i=csize-1;i>=0;--i) {
        dfs2(c[i]); MakeRoot(c[i]);
        if (c[i]==what) break;
    }
/*  for(int i=0;i<n;++i)
        if (nodes[i]->p==NULL) {
            Output(nodes[i]); cout << prev[i] << endl;
        }*/
    N=Size(cycle);
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b); --a; --b;
        if (a!=b)
        if (in[a]&&in[b]) {
            UpdateCycle(a,b);
        } else {
            need=0; Get(a,b);
            if (need) {
                A=B; Get(b,a);
                if (B!=A) UpdateCycle(B,A);
            }
        }
        Push(cycle); Push(nodes[n]);
//      cout << Sum(cycle) << " " << SUM << endl;
//      printf("Answer: ");
        printf("%d\n",((N-Sum(cycle))<=1 ? 1 : (N-Sum(cycle)))+(n-SUM)-N);
/*      for(int i=0;i<n;++i)
            if (nodes[i]->p==NULL) {
                Output(nodes[i]); cout << prev[i] << endl;
        }*/
    }
    return 0;
}