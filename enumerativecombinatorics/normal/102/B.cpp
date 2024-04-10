#include<stdio.h>
char str[100002];
int main(){
    scanf("%s",str);
    if(str[1]==0){
        printf("0\n");
        return 0;
    }
    int ret=1;
    int now=0;
    for(int i=0;str[i];i++)now+=str[i]-'0';
    while(now>9){
        ret++;
        int t=now;
        now=0;
        while(t){
            now+=t%10;
            t/=10;
        }
    }
    printf("%d\n",ret);
}