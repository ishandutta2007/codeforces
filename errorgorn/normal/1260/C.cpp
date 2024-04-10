#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    while (n--){
        int r,b,k;
        scanf("%d%d%d",&r,&b,&k);
        int temp=__gcd(r,b);
        r/=temp;
        b/=temp;
        if (r<b) swap(r,b);
        if ((r-2)/b+1>=k) printf("REBEL\n");
        else printf("OBEY\n"); 
    }
}