#include<bits/stdc++.h>
#define maxn 500050

using namespace std;
char s[maxn];
int n,a,b,c;
bool f;

int main()
{
    scanf("%s",s);n=strlen(s);
    for (int i=1;i<n;i++) if (s[i]<s[i-1]) f=true;
    for (int i=0;i<n;i++) if (s[i]=='a') a++; else if (s[i]=='b') b++; else c++;
    if (!f&&(a==c||b==c)&&a&&b) printf("YES\n"); else printf("NO\n");
    return 0;
}