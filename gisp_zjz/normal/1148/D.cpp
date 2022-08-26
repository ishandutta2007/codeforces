#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=505050;
struct node{
    int x,y,id;
}a[maxn],b[maxn];
bool cmp(node u,node v){
    return u.x<v.x;
}
int n,p,q;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int u,v; scanf("%d%d",&u,&v);
        node tmp;
        tmp.x=u; tmp.y=v;
        tmp.id=i;
        if (u<v) a[++p]=tmp; else b[++q]=tmp;
    }
    sort(a+1,a+p+1,cmp); sort(b+1,b+q+1,cmp);
    if (p>q){
        printf("%d\n",p);
        for (int i=p;i;i--) printf("%d ",a[i].id); puts("");
    } else {
        printf("%d\n",q);
        for (int i=1;i<=q;i++) printf("%d ",b[i].id); puts("");
    }
    return 0;
}