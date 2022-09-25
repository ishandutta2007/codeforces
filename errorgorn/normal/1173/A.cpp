#include <cstdio>
#include <cmath>
using namespace std;
int a,b,c;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    if (a==b && !c) putchar('0');
    else if (abs(a-b)<=c) putchar('?');
    else if (a-b>0) putchar('+');
    else  putchar('-');
}