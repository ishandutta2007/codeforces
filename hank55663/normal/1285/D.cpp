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
struct node{
    node *n[2];
    int Min;
    int sum;
    int dep;
    node():sum(0),Min(0){
        n[0]=n[1]=NULL;
    }
}*root;
int Sum(node *n){
    return n?n->sum:0;
}
int Min(node *n){
    return n?n->Min:0;
}
void pull(node *n){
    n->sum=Sum(n->n[0])+Sum(n->n[1]);
    n->Min=2147483647;
    if(Sum(n->n[0])==0){
        n->Min=min(n->Min,Min(n->n[1]));
    }
    else{
        n->Min=min(n->Min,Min(n->n[0])+(1<<n->dep));
    }
    if(Sum(n->n[1])==0){
        n->Min=min(n->Min,Min(n->n[0]));
    }
    else{
        n->Min=min(n->Min,Min(n->n[1])+(1<<n->dep));
    }
  //  printf("%d\n",n->Min);
}
void add(node *n,bitset<30> b){
    if(n->dep==-1){n->sum++;return;}
    if(b[n->dep]){
        if(!n->n[1]){
            n->n[1]=new node();
            n->n[1]->dep=n->dep-1;
        }
        add(n->n[1],b);
    }
    else{
        if(!n->n[0]){
            n->n[0]=new node();
            n->n[0]->dep=n->dep-1;
        }
        add(n->n[0],b);
    }
    pull(n);
   // node *n=root;
   // for(int i = 29;i>=0;i--)
}
int main(){
    int n;
    scanf("%d",&n);
    root=new node();
    root->dep=29;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        add(root,bitset<30>(x));
    }
    printf("%d\n",Min(root));
}