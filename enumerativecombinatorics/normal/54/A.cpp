#include<stdio.h>
bool p[1000];
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int count=0;
    for(int i=0;i<c;i++){
        int d;
        scanf("%d",&d);
        p[d]=true;
    }
    int last=0;
    for(int i=1;i<=a;i++){
        if(p[i]){
            last=i;
            count++;
        }else if(last+b==i){
            last=i;
            count++;
        }
    }
    printf("%d\n",count);
}