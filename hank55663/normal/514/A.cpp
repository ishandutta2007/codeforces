#include<stdio.h>
#include<string.h>
int main(){
    char x[20];
    scanf("%s",x);
    for(int i=0;i<strlen(x);i++)
        {
            if(x[i]>'4')
            x[i]='9'-x[i]+'0';
            if(x[i]=='0'&&i==0)
                x[i]='9';
        }
    printf("%s",x);
    return 0;
}