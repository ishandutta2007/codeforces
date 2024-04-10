#include<cstdio>
using namespace std;
int n,p;
long long f(int x){
    if(!x)return 1;
    long long t=f(x/2);t=t*t%p;
    if(x&1)t=t*3%p;return t;
}
int main(){
    scanf("%d%d",&n,&p);
    printf("%I64d",(f(n)+p-1)%p);
}