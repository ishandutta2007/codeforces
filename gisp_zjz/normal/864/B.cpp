#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 305
#define inf 1000000020

using namespace std;
typedef long long ll;

char s[maxn];
int n,ans,t,m,l;
bool f[26];

int main()
{
    scanf("%d",&n);
    scanf("%s",s);l=strlen(s);
    t=0;memset(f,true,sizeof(f));ans=0;
    for (int i=0;i<l;i++)
    {
        if (s[i]<='Z'&&s[i]>='A')
        {
            ans=max(ans,t);
            t=0;
            memset(f,true,sizeof(f));
        }
        else{
            if (f[s[i]-'a']){
                f[s[i]-'a']=false;
                t++;
            }
        }
    }
    ans=max(ans,t);
    printf("%d\n",ans);
}