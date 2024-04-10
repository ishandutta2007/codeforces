#include <stdio.h>
using namespace std;
struct segm{int x1,y1,x2,y2;};
segm v[5],auxx;
int x[3],y[3];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int i,ox=0,oy=0,pp=0,aux;
    for(i=1;i<=4&&pp==0;i++){
        scanf("%d%d%d%d",&v[i].x1,&v[i].y1,&v[i].x2,&v[i].y2);
        if(v[i].x1==v[i].x2&&v[i].y1==v[i].y2)
            pp=1;
        else
            if(v[i].x1==v[i].x2){
                oy++;
                y[oy]=i;
                if(v[i].y1>v[i].y2){
                    aux=v[i].y1;
                    v[i].y1=v[i].y2;
                    v[i].y2=aux;
                }
            }
            else
                if(v[i].y1==v[i].y2){
                    ox++;
                    x[ox]=i;
                    if(v[i].x1>v[i].x2){
                        aux=v[i].x1;
                        v[i].x1=v[i].x2;
                        v[i].x2=aux;
                    }
                }
                else
                    pp=1;
    }
    if(v[y[1]].x1>v[y[2]].x1){
        auxx=v[y[1]];
        v[y[1]]=v[y[2]];
        v[y[2]]=auxx;
    }
    if(v[x[1]].y1>v[x[2]].y2){
        auxx=v[x[1]];
        v[x[1]]=v[x[2]];
        v[x[2]]=auxx;
    }
    if(pp==1)
        printf("NO");
    else
        if(ox!=2||oy!=2)
            printf("NO");
        else
            if(v[y[1]].y2-v[y[1]].y1!=v[y[2]].y2-v[y[2]].y1||v[y[1]].y1!=v[y[2]].y1||v[y[1]].y2!=v[y[2]].y2)
                printf("NO");
            else
                if(v[y[1]].x1!=v[x[1]].x1||v[y[1]].y1!=v[x[1]].y1||v[y[2]].x1!=v[x[1]].x2||v[y[2]].y1!=v[x[1]].y2)
                    printf("NO");
                else
                    if(v[y[1]].x2!=v[x[2]].x1||v[y[1]].y2!=v[x[2]].y1||v[y[2]].x2!=v[x[2]].x2||v[y[2]].y2!=v[x[2]].y2)
                        printf("NO");
                    else
                        printf("YES");
    return 0;
}