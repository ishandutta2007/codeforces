#include<bits/stdc++.h>
#define maxn 230405

using namespace std;
int n;
char s[maxn];

int main()
{
    scanf("%d",&n);scanf("%s",s);
    for (int i=0;i<n;i++)
    {
        if (i>0&&(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='o'||s[i-1]=='i'||s[i-1]=='u'||s[i-1]=='y')&&(s[i]=='u'||s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='y')) continue;
        printf("%c",s[i]);
    }
    printf("\n");
}