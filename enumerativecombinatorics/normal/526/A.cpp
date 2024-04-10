#include<stdio.h>
#include<algorithm>
using namespace std;
char str[110];
int main(){
    int a;scanf("%d",&a);
    scanf("%s",str);
    bool ok=false;
    for(int i=0;i<a;i++){
        for(int j=1;j<a;j++){
            if(i+j*4>=a)continue;
            bool OK=true;
            for(int k=0;k<5;k++)if(str[i+j*k]=='.')OK=false;
            if(OK)ok=true;
        }
    }
    if(ok)printf("yes\n");else printf("no\n");
}