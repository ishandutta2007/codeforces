#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,le,ri,n1;
char s[1001];
char ch;

int main()
{
    scanf("%d",&n1);
    le=-2000000000;
    ri=2000000000;
    for(int i=1;i<=n1;i++)
    {
        scanf("%s",s+1);
        scanf("%d",&n);
        ch=getchar();
        while(ch!='Y'&&ch!='N')ch=getchar();
        int l=strlen(s+1);
        if(l==1)
        {
            if(s[1]=='<')
            {
                if(ch=='Y')ri=min(ri,n-1);
                else le=max(le,n);
            }
            else
            {
                if(ch=='Y')le=max(le,n+1);
                else ri=min(ri,n);
            }
        }
        else
        {
            if(s[1]=='<')
            {
                if(ch=='Y')ri=min(ri,n);
                else le=max(le,n+1);
            }
            else
            {
                if(ch=='Y')le=max(le,n);
                else ri=min(ri,n-1);
            }
        }
    }
    if(le>ri)printf("Impossible");
    else printf("%d",le);
}