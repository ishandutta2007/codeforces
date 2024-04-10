#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[10][10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"},
b[20][10]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
int main()
{
    int n;
    scanf("%d",&n);
    if(n<=19)
        printf("%s",b[n]);
    else
        if(n%10==0)
            printf("%s",a[n/10]);
        else
            printf("%s-%s",a[n/10],b[n%10]);
    return 0;
}