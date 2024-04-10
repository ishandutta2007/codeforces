#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[123456];
int n,k;

int main()
{
    scanf("%s",s); n=strlen(s); k=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]-'a'<=k) s[i]='a'+k,k++;
        if (k==26){printf("%s",s);return 0;}
    }
    printf("-1\n");
}