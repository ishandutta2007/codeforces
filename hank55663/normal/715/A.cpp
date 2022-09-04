#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    scanf("%I64d",&n);
    printf("2\n");
    for(long long int i=3;i<=n+1;i++){
        long long int aa=i*(i-1);
        printf("%I64d\n",i*(i-1)*i-(i-2));
    }
}