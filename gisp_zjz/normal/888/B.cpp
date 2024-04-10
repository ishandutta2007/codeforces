#include<bits/stdc++.h>
#define maxn 235000

using namespace std;
char s[maxn];
int a,b,c,d,n,ans;

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for (int i=0;i<n;i++) if (s[i]=='L') a++; else if (s[i]=='R') b++; else if (s[i]=='U') c++; else d++;
    cout << min(a,b)*2+min(c,d)*2 << endl;
}