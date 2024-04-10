#include <cstdio>
#include <cmath>
using namespace std;
int a,b;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d%d",&a,&b);
        a=abs(a-b);
        if (a%5==0) printf("%d\n",a/5);
        else if (a%5<=2) printf("%d\n",a/5+1);
        else printf("%d\n",a/5+2);
    }
}