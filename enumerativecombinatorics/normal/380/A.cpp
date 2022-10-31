#include<stdio.h>
#include<algorithm>
using namespace std;
int p[110000];
int q[110000];
int x[110000];
int y[110000];
long long t[1100000];
int main(){
    int a;
    scanf("%d",&a);
    int S=0;
    long long now=0;
    for(int i=0;i<a;i++){
        scanf("%d",q+i);
        if(q[i]==1)scanf("%d",x+i);
        else scanf("%d%d",x+i,y+i);
    }
    int b;
    scanf("%d",&b);
    for(int i=0;i<b;i++){scanf("%I64d",t+i);t[i]--;}
    int at=0;
    for(int i=0;i<a;i++){
        long long to=now;
        if(q[i]==1)to++;
        else to+=x[i]*y[i];
        while(at<b&&t[at]<to){
            if(q[i]==1)printf("%d ",x[i]);
            else printf("%d ",p[(t[at]-now)%x[i]]);
            at++;
        }
        if(q[i]==1){
            if(S<100000){
                p[S++]=x[i];
            }
            now++;
        }else{
            for(int k=0;k<y[i];k++){
                if(S>=100000)break;
                for(int j=0;j<x[i];j++){
                    if(S>=100000)break;
                    p[S++]=p[j];
                }
            }
            now+=x[i]*y[i];
        }
    }
}