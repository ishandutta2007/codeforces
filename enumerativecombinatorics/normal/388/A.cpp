#include<stdio.h>
#include<algorithm>
using namespace std;
int b[1000];
int c[1000];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)scanf("%d",b+i);
    std::sort(b,b+a);
    for(int i=1;i<=a;i++){
        for(int j=0;j<i;j++){
            c[j]=0;
        }
        bool ok=true;
        for(int j=0;j<a;j++){
            bool OK=false;
            for(int k=0;k<i;k++){
                if(c[k]<=b[j]){
                    OK=true;
                    c[k]++;
                    break;
                }
            }
            if(!OK)ok=false;
        }
        if(ok){
            printf("%d\n",i);
            return 0;
        }
    }
}