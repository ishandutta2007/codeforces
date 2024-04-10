#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if (n&1) printf("0\n");
    else printf("%d\n",(1<<(n>>1)));
}