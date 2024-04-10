#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define N 700005
struct node{
    node *n[2];
    int Size;
    node(){
        n[0]=n[1]=NULL;
        Size=0;
    }
}*root;
LL tot[32][2];
int Size(node *n){
    return n?n->Size:0;
}
void add(int a){
    bitset<30> b(a);
    node *n=root;
    for(int i = 29;i>=0;i--){
        if(b[i]==0){
            tot[i][0]+=Size(n->n[1]);
           //  printf("%d ",Size(n->n[1]));
            if(!n->n[0])n->n[0]=new node();
            n=n->n[0];
            n->Size++;
        }
        else{
            tot[i][1]+=Size(n->n[0]);
          //  printf("%d ",Size(n->n[0]));
            if(!n->n[1])n->n[1]=new node();
            n=n->n[1];
            n->Size++;
        }
    }
   // printf("\n");
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[300005];
    root = new node();
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        add(a[i]);
    }
    LL ans=0;
    LL x=0;
    for(int i = 0;i<30;i++){
        if(tot[i][1]<tot[i][0]){
            x+=(1<<i);
            ans+=tot[i][1];
        }
        else{
            ans+=tot[i][0];
        }
    }
    printf("%lld %lld\n",ans,x);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/