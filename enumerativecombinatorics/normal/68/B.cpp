#include<stdio.h>
int t[10000];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",t+i);
    }
    double left=0;
    double right=1000;
    for(int i=0;i<500;i++){
        double M=(left+right)/2;
        double over=0;
        double under=0;
        for(int j=0;j<a;j++){
            if((double)t[j]<M){
                under+=M-(double)t[j];
            }else{
                over+=(double)t[j]-M;
            }
        }
        if(over*(100.0-(double)b)/100.0>=under)left=M;
        else right=M;
        //printf("%.10lf\n",M);
    }
    printf("%.10lf\n",left);
}