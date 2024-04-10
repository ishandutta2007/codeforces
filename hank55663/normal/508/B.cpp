#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<string.h>
using namespace std;
main(){
    char a[100001];
    scanf("%s",a);
    int ans=-1;
    int length=strlen(a);
    for(int i=0;i<length;i++)
    {
        a[i]-='0';
    }
    for(int i=0;i<length;i++)
    {
        if(a[i]%2==0)
        {
            ans=i;
            if(a[i]<a[length-1])
                break;
        }
    }
    for(int i=0;i<length;i++)
    {
        a[i]+='0';
    }
    if(ans==-1)
        printf("-1");
    else{
    int temp=a[ans];
    a[ans]=a[length-1];
    a[length-1]=temp;
    printf("%s",a);
    }
    return 0;
}