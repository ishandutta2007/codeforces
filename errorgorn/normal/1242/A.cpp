#include <cstdio>
using namespace std;
long long n;
int main(){
    scanf("%lld",&n);
    for (int x=2;x<=1000000;x++){
        if (n%x==0){
            while (n%x==0) n/=x;
            if (n==1) printf("%d\n",x);
            else printf("1\n");
            return 0;
        }
    }
    printf("%lld\n",n);
}