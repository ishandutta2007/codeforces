#include<stdio.h>
#include<algorithm>
using namespace std;
int b[11000];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=2;i<(1<<(a+1));i++){
        scanf("%d",b+i);
    }
    int ret=0;
    for(int i=(1<<a)-1;i>=1;i--){
        int L=b[i*2];
        int R=b[i*2+1];
        ret+=max(L,R)-min(L,R);
        b[i]+=max(L,R);
    }
    printf("%d\n",ret);
}