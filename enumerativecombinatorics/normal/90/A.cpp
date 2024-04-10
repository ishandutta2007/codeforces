#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int ret=0;
    ret=30+(a-1)/2*3;
    if(b)ret=max(ret,30+(b-1)/2*3+1);
    if(c)ret=max(ret,30+(c-1)/2*3+2);
    printf("%d\n",ret);
}