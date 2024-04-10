#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    if(e>d){
        swap(b,c);swap(d,e);
    }
    long long ret=0;
    if(d>1000){
        for(int i=0;(long long)i*d<=a;i++){
            int p=(a-i*d)/e;
            ret=max(ret,(long long)i*b+(long long)p*c);
        }
        printf("%I64d\n",ret);
        return 0;
    }
    for(int i=0;i<=1000;i++){
        if((long long)i*d>a)break;
        int p=(a-i*d)/e;
        ret=max(ret,(long long)i*b+(long long)p*c);
    }
    for(int i=0;i<=1000;i++){
        if((long long)i*e>a)break;
        int p=(a-i*e)/d;
        ret=max(ret,(long long)i*c+(long long)p*b);
    }
    printf("%I64d\n",ret);
}