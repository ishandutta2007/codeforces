#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
#include<string.h>
#define SIZE 700000
using namespace std;
main(){

    char s[SIZE];
    scanf("%s",s);
    double a[SIZE];
    a[1]=1.0+1.0/strlen(s);
    for(int i=2;i<=strlen(s);i++)
    {
          a[i]=a[i-1]+1.0/i;
          a[i]+=1.0/(strlen(s)-i+1.0);

    }
    double ans[SIZE];
    ans[1]=0;
    double Ans=0;
    for(int i=1;i<=strlen(s);i++)
        ans[1]+=1.0/i;
    for(int i=2;i<=ceil(strlen(s)/2.0);i++)
        ans[i]=ans[i-1]+ans[1]-a[i-1];
    for(int i=0;i<strlen(s);i++)
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='Y'||s[i]=='U')
        {
            Ans+=ans[min(i+1,(int)strlen(s)-i)];
        }
    printf("%.7lf",Ans);

    return 0;
}