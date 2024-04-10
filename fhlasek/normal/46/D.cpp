#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

typedef struct linkedList{
  int request,start,end;
  struct linkedList *next;
}LL;

int L,b,f,N,i;
LL list;
LL *l,*n;

int add(int d){
  l=&list;
  while(l->next!=NULL&&l->next->start-l->end<d+b+f) l=l->next;
  if(l->next==NULL) return -1;
  n=(LL*)malloc(sizeof(LL));
  n->start=l->end+b;
  n->end=l->end+b+d;
  n->request=i;
  n->next=l->next;
  l->next=n;
  return n->start;
}

int main(int argc, char *argv[]){
  scanf("%d%d%d%d",&L,&b,&f,&N);
  int a,d;
  list.request=-1;
  list.end=-b;
  list.next=(LL*)malloc(sizeof(LL));
  list.next->request=-2;
  list.next->start=L+f;
  list.next->next=NULL;
  FOR(i,N){
    scanf("%d%d",&a,&d);
    if(a==1) printf("%d\n",add(d));
    else{
      d--;
      l=&list;
      while(l->next->request!=d) l=l->next;
      l->next=l->next->next;
    }
  }
  return 0;
}