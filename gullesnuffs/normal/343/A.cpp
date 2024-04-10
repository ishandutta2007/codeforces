#include <cstdio>
#include <cmath>

using namespace std;

long long rec(long long a, long long b){
    if(a == 0 || b == 0)
        return 0;
    return rec(b, a%b)+a/b;
}

int main(){
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    printf("%I64d\n", rec(a, b));
    return 0;
}