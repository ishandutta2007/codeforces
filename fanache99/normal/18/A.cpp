#include <stdio.h>
using namespace std;
int verif(int x1,int y1,int x2,int y2,int x3,int y3){
    int d1,d2,d3;
    d1=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    d2=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
    d3=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
    if(d1==d2+d3||d2==d1+d3||d3==d1+d2)
        return 1;
    else
        return 0;
}
int s(int x1,int y1,int x2,int y2,int x3,int y3){
    int a;
    a=x1*y2+x2*y3+x3*y1-x3*y2-x1*y3-x2*y1;
    return a;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int x1,y1,x2,y2,x3,y3,pp=0,ppp=0;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    if(verif(x1,y1,x2,y2,x3,y3)==1){
        printf("RIGHT");
        pp=1;
    }
    if(verif(x1-1,y1,x2,y2,x3,y3)==1&&s(x1-1,y1,x2,y2,x3,y3)!=0)
        ppp=1;
    if(verif(x1+1,y1,x2,y2,x3,y3)==1&&s(x1+1,y1,x2,y2,x3,y3)!=0)
        ppp=1;
    if(verif(x1,y1-1,x2,y2,x3,y3)==1&&s(x1,y1-1,x2,y2,x3,y3)!=0)
        ppp=1;
    if(verif(x1,y1+1,x2,y2,x3,y3)==1&&s(x1,y1+1,x2,y2,x3,y3)!=0)
        ppp=1;
    if(verif(x1,y1,x2-1,y2,x3,y3)==1&&s(x1,y1,x2-1,y2,x3,y3)!=0)
        ppp=1;
    if(verif(x1,y1,x2+1,y2,x3,y3)==1&&s(x1,y1,x2+1,y2,x3,y3)!=0)
        ppp=1;
    if(verif(x1,y1,x2,y2-1,x3,y3)==1&&s(x1,y1,x2,y2-1,x3,y3)!=0)
        ppp=1;
    if(verif(x1,y1,x2,y2+1,x3,y3)==1&&s(x1,y1,x2,y2+1,x3,y3)!=0)
        ppp=1;
    if(verif(x1,y1,x2,y2,x3-1,y3)==1&&s(x1,y1,x2,y2,x3-1,y3)!=0)
        ppp=1;
    if(verif(x1,y1,x2,y2,x3+1,y3)==1&&s(x1,y1,x2,y2,x3+1,y3)!=0)
        ppp=1;
    if(verif(x1,y1,x2,y2,x3,y3+1)==1&&s(x1,y1,x2,y2,x3,y3+1)!=0)
        ppp=1;
    if(verif(x1,y1,x2,y2,x3,y3-1)==1&&s(x1,y1,x2,y2,x3,y3-1)!=0)
        ppp=1;
    if(pp==0)
        if(ppp==1)
            printf("ALMOST");
        else
            printf("NEITHER");
    return 0;
}