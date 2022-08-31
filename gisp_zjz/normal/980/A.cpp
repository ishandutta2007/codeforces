#include<bits/stdc++.h>

using namespace std;
char s[1023004];
int a,b,n;

int main()
{
    scanf("%s",s);n=strlen(s);
    for (int i=0;i<n;i++) if (s[i]=='o') a++; else b++;
    if (a==0) {puts("YES");return 0;}
    if (b%a) puts("NO"); else puts("YES");
    return 0;
}