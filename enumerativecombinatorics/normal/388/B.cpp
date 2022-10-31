#include<stdio.h>
#include<algorithm>
using namespace std;
char str[1200][1200];
int main(){
    int a;
    scanf("%d",&a);
    a--;
    printf("498\n");
    for(int i=0;i<498;i++){
        for(int j=0;j<498;j++)
            str[i][j]='N';
    }
    str[0][2]=str[2][0]='Y';
    int f=2;
    for(int i=1;i<=30;i++){
        for(int j=0;j<i;j++){
            str[f][f+i]=str[f+i][f]='Y';
            str[f][f+i+1]=str[f+i+1][f]='Y';
            f++;
        }
    }
    for(int i=0;i<31;i++){
        str[1][497-i]=str[497-i][1]='Y';
    }
    int at=2;
    for(int i=1;i<=30;i++){
        if(!(a&(1<<(30-i)))){
            str[at][at+i]=str[at+i][at]='N';
        }
        at+=i+1;
    }
    for(int i=0;i<498;i++)printf("%s\n",str[i]);
}