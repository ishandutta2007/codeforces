#include<stdio.h>
int l[100];
int r[100];
int t[100];
int c[100];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<b;i++){
        scanf("%d%d%d%d",l+i,r+i,t+i,c+i);
    }
    int ret=0;
    for(int i=1;i<=a;i++){
        int at=0;
        bool ok=false;
        int min=9999999;
        for(int j=0;j<b;j++){
            if(l[j]<=i&&i<=r[j]&&min>t[j]){
                at=j;
                ok=true;
                min=t[j];
            }
        }
        if(ok)ret+=c[at];
    }
    printf("%d\n",ret);
}