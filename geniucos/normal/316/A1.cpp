#include<cstdio>
#include<cstring>
using namespace std;
int s,n,i,ap[300];
char sir[100009];
long long p;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
n=strlen(sir+1);
for(i=1;i<=n;i++)
    ap[sir[i]]++;
for(i='A';i<='J';i++)
    if(ap[i]>0) s++;
if((sir[1]>='0'&&sir[1]<='9')||sir[1]=='?')
{
    p=1;
    for(i=10;i>=10-s+1;i--)
        p=1LL*p*i;
    if(sir[1]=='?')
    {
        p=1LL*p*9;
        ap['?']--;
    }
    printf("%I64d",p);
    for(i=1;i<=ap['?'];i++)
        printf("0");
    printf("\n");
    return 0;
}
p=9;
for(i=9;i>=10-s+1;i--)
    p=1LL*p*i;
printf("%I64d",p);
for(i=1;i<=ap['?'];i++)
    printf("0");
printf("\n");
return 0;
}