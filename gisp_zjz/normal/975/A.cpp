#include<bits/stdc++.h>
#define maxn 2500

using namespace std;
bool f[1<<26];
char s[maxn];
int n,len,k,ans;

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        k=0;scanf("%s",s);len=strlen(s);
        for (int j=0;j<len;j++) k|=(1<<(s[j]-'a'));
        f[k]=true;
    }
    for (int i=0;i<(1<<26);i++) ans+=f[i];
    cout << ans << endl;
    return 0;
}