#include <cstdio>
using namespace std;
int main(){
    int TC;
    scanf("%d",&TC);
    int a,b,c,d,k;
    while (TC--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        a=(a-1)/c+1;
        b=(b-1)/d+1;
        if (a+b>k){
            printf("-1\n");
        }
        else{
            printf("%d %d\n",a,b);
        }
    }
}