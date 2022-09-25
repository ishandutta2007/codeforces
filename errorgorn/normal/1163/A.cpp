#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if (!b) printf("1\n");
    else printf("%d\n",min(b,a-b));
}