#include<stdio.h>
#include<algorithm>
using namespace std;
char str[1200000];
int b[400];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",b+i);
    }
    int ind=0;
    for(int i=0;i<a-1;i++){
        for(int j=0;j<b[i];j++){
            str[ind++]='P';
            str[ind++]='R';
            str[ind++]='L';
        }
        str[ind++]='R';
    }
    for(int j=0;j<b[a-1];j++){
        str[ind++]='P';
            str[ind++]='L';
            str[ind++]='R';
    }printf("%s\n",str);
}