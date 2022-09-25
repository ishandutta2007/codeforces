#include <cstdio>
#include <algorithm>
using namespace std;
int a,b;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d%d",&a,&b);
        printf((__gcd(a,b)==1)?"Finite\n":"Infinite\n");
    }
}