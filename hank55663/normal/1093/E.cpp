
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll

typedef long long LL;
int B[200005];
set_t S[200005];
int n;
void add(int x,int k){
    for(int i=x;i<=n;i+=i&-i){
        S[i].insert(k);
    }    
}
void rm(int x,int k){
    for(int i=x;i<=n;i+=i&-i){
        S[i].erase(k);
    }
}
int query(int x,int k){
    int res=0;
    for(int i=x;i>0;i-=i&-i){
        res+=S[i].order_of_key(k);
    }
    return res;
}
int main(){
   // printf("%d %d %d %d\n",s.order_of_key(1),s.order_of_key(2),s.order_of_key(3),s.order_of_key(4));
    int m;
    scanf("%d %d",&n,&m);
    int a[200005];
    int trans[200005];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        trans[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&B[i]);
        B[i]=trans[B[i]];
        add(i,B[i]);
      //  printf("%d\n",i);
        //printf("%d ",B[i]);
    }
   // printf("\n"
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int ql,qr,l,r;
            scanf("%d %d %d %d",&ql,&qr,&l,&r);
            int sum1=query(r,qr+1)-query(l-1,qr+1);
            int sum2=query(r,ql)-query(l-1,ql);
            //printf("%d %d\n",sum1,sum2);
            printf("%d\n",sum1-sum2);
        }
        else{
            int x,y;
            scanf("%d %d",&x,&y);
            rm(x,B[x]);
            rm(y,B[y]);
            swap(B[x],B[y]);
            add(x,B[x]);
            add(y,B[y]);
        }
    }
}