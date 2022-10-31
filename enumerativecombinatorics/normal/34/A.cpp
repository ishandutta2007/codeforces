#include<stdio.h>
int abs(int a){return a<0?-a:a;}
int dat[100];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)scanf("%d",dat+i);
    int dist=999999;
    int ans=0;
    for(int i=0;i<a;i++){
        if(dist>abs(dat[i]-dat[(i+1)%a])){
            dist=abs(dat[i]-dat[(i+1)%a]);
            ans=i;
        }
    }
    printf("%d %d\n",ans+1,(ans+1)%a+1);
}