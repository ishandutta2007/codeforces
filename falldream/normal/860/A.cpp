#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char st[3005];
int num[30];
inline bool Check(int i){return st[i]!='a'&&st[i]!='e'&&st[i]!='i'&&st[i]!='o'&&st[i]!='u';}
int main()
{
    scanf("%s",st+1);int n=strlen(st+1);
    for(int i=1,j=0,k=0;i<=n;++i)
    {
        if(Check(i)) ++j;else j=0;
        if(j>=3&&!(st[i]==st[i-1]&&st[i-1]==st[i-2])) printf(" "),j=1;
        printf("%c",st[i]);
    }
    return 0;
}