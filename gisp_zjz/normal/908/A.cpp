#include<bits/stdc++.h>
#define maxn 203490

using namespace std;

int n;
char s[maxn];
int ans;

int main()
{
    scanf("%s",s);n=strlen(s);
    for (int i=0;i<n;i++) if (s[i]<='9'&&(s[i]&1)) ans++;
    for (int i=0;i<n;i++) if (s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i') ans++;
    printf("%d\n",ans);return 0;
}