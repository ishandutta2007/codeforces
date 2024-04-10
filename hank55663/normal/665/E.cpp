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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
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
void add(node *n, bitset<40> &b, int now){
    if(now==-1){
        n->sum++;
        return;
    }
    if(!n->n[b[now]]){
        n->n[b[now]]=new node();
    }
    add(n->n[b[now]],b,now-1);
    pull(n);
}
int query(node *n, bitset<40> &k, bitset<40> &b, int now){
    if(!n)return 0;
    if(now==-1){
        return Sum(n);
    }
    if(k[now]==1){
        return query(n->n[1-b[now]],k,b,now-1);
    }
    else{
        return Sum(n->n[1-b[now]])+query(n->n[b[now]],k,b,now-1);
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    root = new node();
    bitset<40> b(0);
    add(root,b,30);
    int pre=0;
    LL ans=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        pre^=x;
        bitset<40> kk(k),bb(pre);
        ans+=query(root,kk,bb,30);
        add(root,bb,30);
    }
    printf("%lld\n",ans);
}
/*
0
10
20
30
40

4+3+3+4+3+2+2+1
13:00
11:

11:24
11:48
12:12
12:36
13:00
13:24
13:48
14:12
14:36
*/