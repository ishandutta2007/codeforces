#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
struct node{
    node *n[2];
    int word;
}*root;
void add(int a){
    node *n=root;
    vector<int> v;
    for(int i =0;i<20;i++){
        v.pb(a&1);
        a>>=1;
    }
    reverse(v.begin(),v.end());
    for(int i = 0;i<20;i++){
        if(!n->n[v[i]]){
            n->n[v[i]]=new node();
        }
        n=n->n[v[i]];
    }
    n->word=1;
}
int query(int s){
    node *n=root;
    vector<int> v;
    for(int i = 0;i<20;i++){
        v.pb(s&1);
        s>>=1;
    }
    reverse(v.begin(),v.end());
    int res=0;
    for(int i = 0;i<20;i++){
        res<<=1;
        if(n->n[v[i]]){
            n=n->n[v[i]];
        }
        else{
            n=n->n[v[i]^1];
            res++;
        }
    }
    return res;
}
int vis[1<<20];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    root = new node();
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        vis[x]=1;
        //add(x);
    }
    for(int i = 0;i<(1<<20);i++){
        if(!vis[i]){
            add(i);
        }
    }
    int qu=0;
    while(m--){
        int x;
        scanf("%d",&x);
        qu^=x;
        printf("%d\n",query(qu));
    }
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/