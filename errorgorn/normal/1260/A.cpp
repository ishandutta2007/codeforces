#include <cstdio>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    while (n--){
        int a,b;
        scanf("%d%d",&a,&b);
        int base=b/a;
        int extra=b%a;
        printf("%d\n",base*base*(a-extra)+(base+1)*(base+1)*extra);
    }
}