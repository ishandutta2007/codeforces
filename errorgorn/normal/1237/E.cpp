#include <cstdio>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int t=1;
    while (t<1000005){
        if (n==t || n==t+1){
            printf("1\n");
            return 0;
        }
        if (t%2==0){
            t<<=1;
            t+=1;
        }
        else{
            t<<=1;
            t+=2;
        }
    }
    printf("0\n");
}