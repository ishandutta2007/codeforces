#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[100010];
    int i,j;
    gets(arr);
    int BTCHPLEASE = strlen(arr);
    for(i=0;i<BTCHPLEASE;i++){
        if(arr[i]=='0'){
            for(j=i;j<BTCHPLEASE-1;j++){
                arr[j]=arr[j+1];
            }
            break;
        }
    }
    for(i=0;i<BTCHPLEASE-1;i++){
        printf("%c",arr[i]);
    }
    return 0;
}