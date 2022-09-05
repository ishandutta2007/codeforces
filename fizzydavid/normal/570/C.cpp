//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m,ans;
char s[300111];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<n;i++)if(s[i]==s[i+1]&&s[i]=='.')ans++;
    for(int i=1;i<=m;i++)
    {
        int x;char c;
        scanf("%d %c",&x,&c);
        if((s[x]=='.')==(c=='.'))
        {
            printf("%d\n",ans);
            continue;
        }
        if(c=='.')
        {
            if(s[x+1]=='.')ans++;
            if(s[x-1]=='.')ans++;
            printf("%d\n",ans);
        }
        else
        {
            if(s[x+1]=='.')ans--;
            if(s[x-1]=='.')ans--;
            printf("%d\n",ans);
        }
        s[x]=c;
    }
    return 0;
}