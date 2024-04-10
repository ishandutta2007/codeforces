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
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 200005
char a[1000005];
struct node{
    node *l,*r;
    int tag;
    int Max,Min;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(0),Max(0),Min(0){
 
    }
}*root;
void build(node *n){
    if(n->a==n->b)return ;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
int Max(node *n){
    return n->Max+n->tag;
}
int Min(node *n){
    return n->Min+n->tag;
}
void pull(node *n){
    n->Max=max(Max(n->l),Max(n->r));
    n->Min=min(Min(n->l),Min(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
int main(){
    root = new node(1,2e6);
    build(root);
    int n;
    scanf("%d",&n);
    char c[1000005];
    scanf("%s",c);
    int now=1;
    int tot=0;
    for(int i = 0;i<n;i++){
        if(c[i]=='('){
            tot++;
            if(a[now]=='(')add(root,now,2000000,-1),tot--;
            else if(a[now]==')')add(root,now,2000000,1),tot++;
            a[now]=c[i];
            add(root,now,2000000,1);
        }
        else if(c[i]==')'){
            tot--;
            if(a[now]=='(')add(root,now,2000000,-1),tot--;
            else if(a[now]==')')add(root,now,2000000,1),tot++;
            a[now]=c[i];
            add(root,now,2000000,-1);
        }
        else if(c[i]=='L'){
            now--;
            if(now<1)now=1;
        }
        else if(c[i]=='R'){
            now++;
        }
        else{
            if(a[now]=='(')add(root,now,2000000,-1),tot--;
            else if(a[now]==')')add(root,now,2000000,1),tot++;
            a[now]=c[i];
        }
        if(tot==0&&Min(root)>=0){
            printf("%d ",Max(root));
        }
        else{
            printf("-1 ");
        }
    }
    printf("\n");
}