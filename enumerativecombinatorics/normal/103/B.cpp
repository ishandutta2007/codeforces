#include<stdio.h>
int UF[101];
int FIND(int a){
    if(UF[a]<0)return a;
    return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
    a=FIND(a);
    b=FIND(b);
    if(a==b)return;
    UF[a]+=UF[b];
    UF[b]=a;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a+1;i++)UF[i]=-1;
    int dif=0;
    for(int i=0;i<b;i++){
        int c,d;
        scanf("%d%d",&c,&d);
        if(FIND(c)!=FIND(d)){
            dif++;
            UNION(c,d);
        }
    }
    if(a==b&&dif==a-1)printf("FHTAGN!\n");
    else printf("NO\n");
}