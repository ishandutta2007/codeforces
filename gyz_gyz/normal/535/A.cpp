#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    if(n==0)printf("zero");
    if(n==1)printf("one");
    if(n==2)printf("two");
    if(n==3)printf("three");
    if(n==4)printf("four");
    if(n==5)printf("five");
    if(n==6)printf("six");
    if(n==7)printf("seven");
    if(n==8)printf("eight");
    if(n==9)printf("nine");
    if(n==10)printf("ten");
    if(n==11)printf("eleven");
    if(n==12)printf("twelve");
    if(n==13)printf("thirteen");
    if(n==14)printf("fourteen");
    if(n==15)printf("fifteen");
    if(n==16)printf("sixteen");
    if(n==17)printf("seventeen");
    if(n==18)printf("eighteen");
    if(n==19)printf("nineteen");
    if(n>19){
        if(n/10==2)printf("twenty");
        if(n/10==3)printf("thirty");
        if(n/10==4)printf("forty");
        if(n/10==5)printf("fifty");
        if(n/10==6)printf("sixty");
        if(n/10==7)printf("seventy");
        if(n/10==8)printf("eighty");
        if(n/10==9)printf("ninety");
        n%=10;
        if(n==1)printf("-one");
        if(n==2)printf("-two");
        if(n==3)printf("-three");
        if(n==4)printf("-four");
        if(n==5)printf("-five");
        if(n==6)printf("-six");
        if(n==7)printf("-seven");
        if(n==8)printf("-eight");
        if(n==9)printf("-nine");
    }
}