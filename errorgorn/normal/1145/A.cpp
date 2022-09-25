#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int s,e,m;
    int first,last;
    int longest;
    bool sorted;
    node *l,*r;
    node(int _s,int _e){
        s=_s,e=_e,m=(s+e)>>1;
        sorted=true;
        if (s==e){
            scanf("%d",&first);
            last=first;
            longest=1;
        }
        else{
            l=new node(s,m);
            r=new node(m+1,e);
            if (l->sorted && r->sorted && l->last<=r->first){
                //printf("%d %d\n",s,e);
                first=l->first;
                last=r->last;
                longest=l->longest<<1;
            }
            else{
                longest=max(l->longest,r->longest);
                sorted=false;
            }
        }
    }
}*root;
int main(){
    int n;
    scanf("%d",&n);
    root=new node(1,n);
    printf("%d\n",root->longest);
}