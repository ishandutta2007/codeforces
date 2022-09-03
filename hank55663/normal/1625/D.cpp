#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *n[2];
    int num;
    node(){
        n[0]=n[1]=NULL;
        num=0;
    }
}*root;
void add(node *&n,int k,int i,int j){
    if(!n)n=new node();
    if(j==-1){
        n->num=i;
        return;
    }
    add(n->n[(k>>j)&1],k,i,j-1);
}
vector<int> query(node *l,node *r,int k,int i){
    if(i==-1){
        vector<int> v;
        if(l)v.pb(l->num);
        if(r)v.pb(r->num);
        return v;
    }
    if(!l&&!r)return vector<int>();
    if(!l){
        return query(l,r->n[0]?r->n[0]:r->n[1],k,i-1);
    }
    if(!r) return query(l->n[0]?l->n[0]:l->n[1],r,k,i-1);
    if((k>>i)&1){
        vector<int> v1=query(l->n[0],r->n[1],k,i-1);
        vector<int> v2=query(l->n[1],r->n[0],k,i-1);
        if(v1.size()>v2.size())swap(v1,v2);
        while(v2.size()>2)v2.pop_back();
        return v2;
    }
    else{
        if(l==r){
            vector<int> v1=query(l->n[0],l->n[0],k,i-1);
            vector<int> v2=query(r->n[1],r->n[1],k,i-1);
            for(auto it:v2)v1.pb(it);
            return v1;
        }
        else{
            if(l->n[0]&&r->n[1]){
                vector<int> v1=query(l->n[0],NULL,k,i-1),v2=query(NULL,r->n[1],k,i-1);
                v1.pb(v2.back());
                return v1;
            }
            if(l->n[1]&&r->n[0]){
                vector<int> v1=query(l->n[1],NULL,k,i-1),v2=query(NULL,r->n[0],k,i-1);
                v1.pb(v2.back());
                return v1;
            }
            vector<int> v1=query(l->n[0],r->n[0],k,i-1);
            vector<int> v2=query(l->n[1],r->n[1],k,i-1);
            if(v1.size()>v2.size())swap(v1,v2);
            while(v2.size()>2)v2.pop_back();
            return v2;
        }
    }
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k==0){
        printf("%d\n",n);
        for(int i = 1;i<=n;i++)printf("%d ",i);
        printf("\n");
        return;
    }
    int a[300005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        add(root,a[i],i,29);
    }
    vector<int> v=query(root,root,k,29);
    if(v.size()==1)printf("-1\n");
    else{
        printf("%d\n",v.size());
        for(auto it:v)printf("%d ",it);
        printf("\n");
    }
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}