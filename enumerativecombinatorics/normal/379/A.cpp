#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int ret=a;
    while(a>=b){
        ret++;
        a-=b;
        a+=1;
    }
    printf("%d\n",ret);
}