#include <cstdio>
using namespace std;
int n,m;
bool arr[530005];
int k;
struct node{
    int sig;
    int bit;
    int val;
    node *child[2];
    node(int _sig,int _bit,int _val){
        sig=_sig;
        bit=_bit;
        val=_val;
        if (sig){
            child[0]=new node(sig-1,0,val<<1);
            child[1]=new node(sig-1,1,(val<<1)+1);
            val=child[0]->val+child[1]->val;
        }
        else{
            if (arr[val]) val=1;
            else val=0;
        }
        sig--;
    }
    int query(){
        if (sig==-1) return 0;
        else{
            int b=(k>>sig)&1;
            //printf("%d %d %d\n",sig,b,child[b]->val);
            if (child[b]->val==(1<<sig)){
                return child[1^b]->query()+((1^b)<<sig);
            }
            else{
                return child[b]->query()+(b<<sig);
            }
        }
    }
}*root;
int main(){
    scanf("%d%d",&n,&m);
    int t;
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        arr[t]=true;
    }
    root=new node(19,0,0);
    while (m--){
        scanf("%d",&t);
        k^=t;
        printf("%d\n",k^root->query());
    }
}