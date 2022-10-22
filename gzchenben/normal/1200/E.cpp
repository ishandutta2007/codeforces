#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,fail[1000005],len;
char s[1000005],t[1000005];
void merge()
{
    int lent=strlen(t+1);
    int Now=-1;
    for(int i=1;i<=lent;i++)
    {
        while(t[i]!=t[Now+1] && Now>=1) Now=fail[Now];
        if(t[i]==t[Now+1] || Now==-1) Now++;
        fail[i]=Now;  
    }
    Now=0;
    for(int i=max(len-lent+1,1);i<=len;i++)
    {
        while(s[i]!=t[Now+1] && Now>=1) Now=fail[Now];
        if(s[i]==t[Now+1]) Now++;
    }
//    printf("paired: %d\n",Now);
    for(int i=Now+1;i<=lent;i++)
    {
        s[++len]=t[i];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",t+1);
        merge();
    }
    for(int i=1;i<=len;i++) printf("%c",s[i]);
    printf("\n");
}