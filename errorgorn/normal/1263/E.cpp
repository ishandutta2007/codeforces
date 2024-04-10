#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
  int s,e,m;
  int minv,maxv,lazy;
  node *l,*r;
  node(int _s,int _e){
    s=_s,e=_e,m=(s+e)>>1,lazy=0,minv=0,maxv=0;
    if (s!=e){
      l=new node(s,m);
      r=new node(m+1,e);
    }
  }
  void lazy_add(){
    minv+=lazy;
    maxv+=lazy;
    if (s!=e) (l->lazy)+=lazy,(r->lazy)+=lazy; //edit this for diff
    lazy=0;
  }
  int maxquery(int i,int j){
    lazy_add();
    if (i==s && j==e) return maxv;
    else if (j<=m) return l->maxquery(i,j);
    else if (m<i) return r->maxquery(i,j);
    else return max(l->maxquery(i,m),r->maxquery(m+1,j));//edit this for diff
  }
  int minquery(int i,int j){
    lazy_add();
    if (i==s && j==e) return minv;
    else if (j<=m) return l->minquery(i,j);
    else if (m<i) return r->minquery(i,j);
    else return min(l->minquery(i,m),r->minquery(m+1,j));//edit this for diff
  }
  void update(int i,int j, long long k){
    if (i==s && j==e){
      lazy+=k;
      return;
    }
    else if (j<=m) l->update(i,j,k);
    else if (m<i) r->update(i,j,k);
    else l->update(i,m,k),r->update(m+1,j,k);
    l->lazy_add(),r->lazy_add();
    minv=min(l->minv,r->minv);
    maxv=max(l->maxv,r->maxv);
  }
}*root=new node(0,1000005);

int n;
char arr[1000005];
int main(){
    scanf("%d",&n);
    getchar();
    
    char c;
    int cursor=0,end=0;
    int prev=0;
    for (int x=0;x<n;x++){
        c=getchar();
        if (c=='R') cursor++,end=max(end,cursor);
        else if (c=='L') cursor=max(0,cursor-1);
        else{
            if (c=='(') root->update(cursor,1000005,1);
            else if (c==')') root->update(cursor,1000005,-1);
            if (arr[cursor]=='(') root->update(cursor,1000005,-1);
            else if (arr[cursor]==')') root->update(cursor,1000005,1);
        
            arr[cursor]=c;
            if (root->minquery(0,end)<0 || root->minquery(end,end)){
                prev=-1;
            }
            else{
                prev=root->maxquery(0,end);
            }
        }
        
        //for (int x=0;x<=end;x++) printf("%d ",root->maxquery(x,x));
        //printf("\n");
        //printf("%d %d\n",root->minquery(0,end),root->maxquery(0,end));
        printf("%d ",prev);
    }
}