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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int cnt[1<<21];
int Min[1<<21];
void add(int x,int now,int i){
    if(cnt[x]>=2)return;
    cnt[x]++;
  //  printf("%d\n",x);
    if(cnt[x]==2){
        Min[x]=i;
      //  printf("%d %d\n",x,i);
    }
    if(now==0)return;
    add(x-(now&-now),now-(now&-now),i);
    while(now){
        now-=(now&-now);
        if(now)
        add(x-(now&-now),now-(now&-now),i);
    }
}
int a[1000005];
struct node{
    node *n[2];
    int Min;
    int dep;
    node(int _dep):dep(_dep){
        n[0]=n[1]=NULL;
    }
}*root;
void pull(node *n){
    n->Min=max(n->n[0]->Min,n->n[1]->Min);
}
void build(node *n,int val){
    if(n->dep==0){
        n->Min=Min[val];
        return;
    }
    n->n[0]=new node(n->dep-1);
    n->n[1]=new node(n->dep-1);
    build(n->n[0],val<<1);
    build(n->n[1],(val<<1)+1);
    pull(n);
}
int query(node *x,int qu,int val,int i){
    if(x->dep==0)return val;
    if(qu&(1<<(x->dep-1))){
        return query(x->n[0],qu,val<<1,i);
    }
    else{
        if(x->n[1]->Min>i){
            return query(x->n[1],qu,(val<<1)+1,i);
        }
        else{
            return query(x->n[0],qu,val<<1,i);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = n-1;i>=0;i--){
        add(a[i],a[i],i);
     //   printf("i:%d\n",i);
    }
   // printf("?\n");
    root= new node(21);
    build(root,0);
   // printf("!\n");
    int ans=0;
    for(int i = 0;i<n;i++){
        int x=query(root,a[i],0,i);
        ans=max(ans,a[i]|x);
    }
    printf("%d\n",ans);
}