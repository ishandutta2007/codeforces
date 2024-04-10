#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int a;
    scanf("%d",&a);
    if(a%2)printf("%d %d\n",9,a-9);
    else printf("%d %d\n",8,a-8);
}