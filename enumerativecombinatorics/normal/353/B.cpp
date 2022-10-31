#include<stdio.h>
#include<algorithm>
using namespace std;
int b[200];
int c[200];
int d[100];
int e[100];
pair<int,int> dat[100];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<2*a;i++){
        scanf("%d",b+i);
    }
    int now=0;
    for(int i=10;i<=99;i++){
        int v=0;
        for(int j=0;j<2*a;j++){
            if(i==b[j]){
                v++;
            }
        }
        dat[i-10]=make_pair(v,i);
    }
    std::sort(dat,dat+90);
    for(int i=0;i<90;i++){
        int T=dat[i].second;
        for(int j=0;j<2*a;j++){
            if(T==b[j]){
                c[j]=(++now)%2;
                if(now%2==0)d[T]=1;
                else e[T]=1;
            }
        }
    }
    int A=0;
    int B=0;
    for(int i=0;i<100;i++){
        if(d[i])A++;
        if(e[i])B++;
    }
    printf("%d\n",A*B);
    for(int i=0;i<2*a;i++){
        if(i)printf(" ");
        printf("%d",c[i]+1);
    }
    printf("\n");
}