#include <cstdio>
using namespace std;
struct seg{
    int s,e,m;
    int val;
    int layer;
    seg *l,*r;
    
    seg(int _s,int _e, int _l){
        s=_s,e=_e,layer=_l;
        m=(s+e)>>1;
        if (s!=e){
            l=new seg(s,m,layer-1);
            r=new seg(m+1,e,layer-1);    
        }
    }
    
    void update(int i,int j){
        if (s==e) val=j;
        else{
            if (i<=m) l->update(i,j);
            else r->update(i,j);
            if (layer&1){
                val=l->val|r->val;
            }
            else{
                val=l->val^r->val;
            }
        }
    }
    
    int query(){
       return val; 
    }
}*root;

int n,q;
int arr[150005];


int main(){
    scanf("%d%d",&n,&q);
    root=new seg(1,(1<<n),n);
    for (int x=1;x<=(1<<n);x++){
        scanf("%d",&arr[x]);
        root->update(x,arr[x]);
    }
    
    int a,b;
    while (q--){
        scanf("%d%d",&a,&b);
        arr[a]=b;
        root->update(a,arr[a]);
        printf("%d\n",root->query());
    }
}