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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
struct node{
    node *n[2];
    int sum;
    node(){
        n[0]=n[1]=NULL;
        sum=0;
    }
}*root;
int Sum(node *n){
    return n?n->sum:0;
}
void pull(node *n){
    n->sum=Sum(n->n[0])+Sum(n->n[1]);
}
void add(node *n,int x,int level){
    if(level==-1){
        n->sum++;
        return ;
    }
    if(x&(1<<level)){
        if(!n->n[1])n->n[1]=new node();
        add(n->n[1],x,level-1);
    }
    else{
        if(!n->n[0])n->n[0]=new node();
        add(n->n[0],x,level-1);
    }
    pull(n);
}
void erase(node *n,int x,int level){
    if(level==-1){
        n->sum--;
        return ;
    }
    if(x&(1<<level)){
        if(!n->n[1])n->n[1]=new node();
        erase(n->n[1],x,level-1);
    }
    else{
        if(!n->n[0])n->n[0]=new node();
        erase(n->n[0],x,level-1);
    }
    pull(n);
}
int query(node *n,int x,int level){
    if(level==-1)return 0;
    if(x&(1<<level)){
        if(Sum(n->n[0]))return query(n->n[0],x,level-1)+(1<<level);
        else return query(n->n[1],x,level-1);
    }
    else{
        if(Sum(n->n[1]))return query(n->n[1],x,level-1)+(1<<level);
        else return query(n->n[0],x,level-1);
    }
}
int main(){ 
    int q;
    scanf("%d",&q);
    root = new node();
    add(root,0,30);
    while(q--){
        char c;
        int x;
        scanf(" %c %d",&c,&x);
        if(c=='+'){
            add(root,x,30);
        }
        else if(c=='-'){
            erase(root,x,30);
        }
        else{
            printf("%d\n",query(root,x,30));
        }
    }
}
/**/