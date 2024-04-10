//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<deque>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int l[25000011],r[25000011],cnt[25000011];
char s[5011];
int ind;
bool dp[5011][5011];
int dpcnt[5011][5011],n,sz;
int main()
{
    sz=1;
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&ind);
    for(int le=1;le<=n;le++)
    {
        for(int i=1;i<=n-le+1;i++)
        {
            int j=i+le-1;
            dp[i][j]=(i+2>=j-2||dp[i+2][j-2])&&s[i]==s[j];
            if(dp[i][j])dpcnt[i][0]++,dpcnt[i][j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int p=1;
        int tcnt=dpcnt[i][0];
        cnt[p]+=tcnt;
        for(int j=i;j<=n;j++)
        {
            if(tcnt==0)break;
            if(s[j]=='a')
            {
                if(l[p]==0)l[p]=++sz;
                p=l[p];
            }
            else
            {
                if(r[p]==0)r[p]=++sz;
                p=r[p];
            }
            cnt[p]+=tcnt;
            tcnt-=dpcnt[i][j];
        }
    }
    int p=1;
    while(true)
    {
        if(l[p]&&!r[p])
        {
            if(cnt[p]-cnt[l[p]]>=ind)break;
            ind-=cnt[p]-cnt[l[p]];
            p=l[p];
            putchar('a');
        }
        else if(!l[p]&&r[p])
        {
            if(cnt[p]-cnt[r[p]]>=ind)break;
            ind-=cnt[p]-cnt[r[p]];
            p=r[p];
            putchar('b');
        }
        else
        {
            if(cnt[p]-cnt[r[p]]<ind)
            {
                ind-=cnt[p]-cnt[r[p]];
                p=r[p];
                putchar('b');
            }
            else if(cnt[p]-cnt[r[p]]-cnt[l[p]]<ind)
            {
                ind-=cnt[p]-cnt[r[p]]-cnt[l[p]];
                p=l[p];
                putchar('a');
            }
            else break;
        }
    }
    return 0;
}