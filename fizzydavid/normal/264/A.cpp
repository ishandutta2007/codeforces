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
char s[1000111];
int n,nxt[1000111],pre[1000111];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=2;i<=n;i++)
    {
        char op=s[i-1];
        if(op=='l')
        {
            pre[i]=pre[i-1];
            nxt[i]=i-1;
            nxt[pre[i-1]]=i;
            pre[i-1]=i;
        }
        else
        {
            pre[i]=i-1;
            nxt[i]=nxt[i-1];
            pre[nxt[i-1]]=i;
            nxt[i-1]=i;
        }
    }
    int p;
    for(int i=1;i<=n;i++)if(pre[i]==0)p=i;
    while(p!=0)
    {
        printf("%d\n",p);
        p=nxt[p];
    }
    return 0;
}