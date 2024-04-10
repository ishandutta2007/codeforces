#include<stdio.h>
int pri[27];
struct tree{
    tree *l,*r;
    char val;
    tree(char _val):r(NULL),l(NULL),val(_val){}
};
tree* merge(tree *a,tree* b){
    if(!a||!b) return a? a:b;
    if(pri[a->val-'A']<pri[b->val-'A']){
        a->r=merge(a->r,b);
        return a;
    }
    else{
        b->l=merge(a,b->l);
        return b;
    }
}
void post(tree* t){
    if(t){
        post(t->l);
        post(t->r);
        printf("%c",t->val);
    }
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    for(int i=0;a*i<=c;i++)
        if((c-i*a)%b==0)
    {

        printf("Yes\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}