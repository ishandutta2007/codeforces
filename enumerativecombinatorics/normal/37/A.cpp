#include<stdio.h>
int t[10000];
int n[10000];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)scanf("%d",t+i);
    for(int i=0;i<a;i++)n[t[i]]++;
    int ret=0;
    int size=0;
    for(int i=0;i<10000;i++){
        if(ret<n[i])ret=n[i];
        if(n[i])size++;
    }
    printf("%d %d\n",ret,size);
}