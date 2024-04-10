#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *n[2];
    int sum;
    node(){
        n[0]=n[1]=NULL;
        sum=0;
    }
}*root;
void add(bitset<30> b){
    node *n=root;
    root->sum++;
    for(int j = 29;j>=0;j--){
        if(!n->n[b[j]]){
            n->n[b[j]]=new node();
        }
        n=n->n[b[j]];
        n->sum++;
    }
}
int ans=0;
void dfs(node *n,int sum){
    ans=max(ans,sum+min(n->sum,2));
    if(n->n[0]){
        if(n->n[1])dfs(n->n[0],sum+1);
        else dfs(n->n[0],sum);
    }
    if(n->n[1]){
        if(n->n[0])dfs(n->n[1],sum+1);
        else dfs(n->n[1],sum);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    root=new node();
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        bitset<30> b(a[i]);
        add(b);
    }
    dfs(root,0);
    printf("%d\n",n-ans);
}

int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}