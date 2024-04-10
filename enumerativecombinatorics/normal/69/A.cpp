#include<stdio.h>
int d[3];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int e,f,g;
        scanf("%d%d%d",&e,&f,&g);
        d[0]+=e;
        d[1]+=f;
        d[2]+=g;
    }
    if(d[0]==0&&d[1]==0&&d[2]==0)printf("YES\n");
    else printf("NO\n");
}