#include <cstdio>
using namespace std;
int TC;
long long n,k;
int main(){
    scanf("%d",&TC);
    for (int x=0;x<TC;x++){
        scanf("%lld",&n);
        k=0;
        while (n%2==0){
            n/=2;
            k+=1;
        }
        while (n%3==0){
            n/=3;
            k+=2;
        }
        while (n%5==0){
            n/=5;
            k+=3;
        }
        if (n!=1) k=-1;
        printf("%lld\n",k);
    }
}