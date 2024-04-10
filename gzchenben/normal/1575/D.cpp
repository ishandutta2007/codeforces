#include<cstdio>
#include<cstring>
using namespace std;
char s[10];
int num[128];
int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    if(len==1)
    {
        if(s[len]=='0' || s[len]=='X' || s[len]=='_') printf("1\n");
        else printf("0\n");
        return 0;
    }
    if(s[1]=='0'){printf("0\n");return 0;}
    for(int i=1;i<=len;i++) num[s[i]]++;
    int ans=1;
    if(s[len-1]=='0' && s[len]=='0')
    {
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='2' && s[len]=='5')
    {
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='5' && s[len]=='0')
    {
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='7' && s[len]=='5')
    {
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='X' && s[len]=='0')
    {
        if(s[1]!='X') ans*=2;
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='X' && s[len]=='5')
    {
        ans*=2;
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='_' && s[len]=='0')
    {
        if(len!=2) ans*=2;
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='_' && s[len]=='5')
    {
        ans*=2;
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='0' && s[len]=='X')
    {
        if(s[1]=='X') {printf("0\n");return 0;}
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='2' && s[len]=='X')
    {
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='5' && s[len]=='X')
    {
        if(s[1]=='X') {printf("0\n");return 0;}
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='7' && s[len]=='X')
    {
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='0' && s[len]=='_')
    {
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='2' && s[len]=='_')
    {
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='5' && s[len]=='_')
    {
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='7' && s[len]=='_')
    {
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='_' && s[len]=='X')
    {
        if(len==2) {printf("3\n");return 0;}
        if(s[1]!='X') ans*=4;
        else ans*=2;
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='X' && s[len]=='X')
    {
        if(len==2 || s[1]=='X') {printf("0\n");return 0;}
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='X' && s[len]=='_')
    {
        if(len==2) {printf("3\n");return 0;}
        if(s[1]!='X') ans*=4;
        else ans*=3;
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else if(s[len-1]=='_' && s[len]=='_')
    {
        ans*=4;
        if(num['X']) ans*=(s[1]=='X' ? 9 : 10);
        if(len==2) {printf("3\n");return 0;}
        for(int i=1;i<=len-2;i++) if(s[i]=='_') ans*=(i==1 ? 9 : 10);
    }
    else ans=0;
    printf("%d\n",ans);
}