#include<cstdio>
#include<cstring>
using namespace std;
int st,n,i;
char sir[100010];
int cor(char v)
{
    if(v>='a'&&v<='z') return 1;
    if(v>='A'&&v<='Z') return 1;
    if(v=='.'||v==','||v=='?'||v=='!') return 1;
    if(v>='0'&&v<='9') return 1;
    return 0;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
n=strlen(sir+1);
st=1;
while(sir[st]==' ') st++;
for(i=st;i<=n;i++)
{
    if(sir[i]=='"')
    {
        printf("<");
        i++;
        while(sir[i]!='"'&&i<=n)
        {
            printf("%c",sir[i]);
            i++;
        }
        printf(">\n");
        continue;
    }
    if(sir[i]==' ')
    {
        while(sir[i]==' '&&i<=n) i++;
    }
    if(sir[i]=='"')
    {
        i--;
        continue;
    }
    if(cor(sir[i]))
    {
        printf("<");
        while(cor(sir[i])&&i<=n)
        {
            printf("%c",sir[i]);
            i++;
        }
        printf(">\n");
    }
    i--;
}
return 0;
}