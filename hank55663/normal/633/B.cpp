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
    int m;
    scanf("%d",&m);
    int zero=0;
    for(int i=1;zero<m;i++){
        zero++;
        int a=i;
        while(a%5==0){
            a/=5;
            zero++;
        }
        if(zero==m){
            printf("5\n%d %d %d %d %d\n",i*5,i*5+1,i*5+2,i*5+3,i*5+4,i*5+5);
        return 0;
        }
    }
    printf("0\n");
    return 0;
}