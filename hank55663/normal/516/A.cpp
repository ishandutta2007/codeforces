#include<stdio.h>
#include<algorithm>
main(){
    int n;
    char a[15];
    int num[8]={0,0,0,0,0,0,0,0};
    scanf("%d",&n);
    scanf("%s",a);
    for(int i=0;i<n;i++)
    {
        if(a[i]>='2')
            num[2]++;
        if(a[i]>='3')
            num[3]++;
        if(a[i]>='4')
            num[2]+=2;
        if(a[i]>='5')
            num[5]++;
        if(a[i]>='6')
        {
            num[2]++;
            num[3]++;
        }
        if(a[i]>='7')
            num[7]++;
        if(a[i]>='8')
            num[2]+=3;
        if(a[i]>='9')
            num[3]+=2;
    }
    int ans[100];
    int j=0;
    if(num[7]!=0)
        while(num[7]>0){
            ans[j]=7;
            j++;
            num[2]-=4;
            num[3]-=2;
            num[5]--;
            num[7]--;
        }
    if(num[5]!=0)
    while(num[5]>0){
        ans[j]=5;
        j++;
        num[2]-=3;
        num[3]--;
        num[5]--;
    }
    if(num[3]!=0)
    while(num[3]>0){
        ans[j]=3;
        j++;
        num[2]--;
        num[3]--;
    }
    if(num[2]!=0)
    while(num[2]>0){
        ans[j]=2;
        j++;
        num[2]--;
    }
    for(int i=0;i<j;i++)
        printf("%d",ans[i]);
}