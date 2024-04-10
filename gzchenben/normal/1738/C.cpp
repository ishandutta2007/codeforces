#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,ans[105][105][2];
int dp(int x,int y,int flag)
{
    if(ans[x][y][flag]) return ans[x][y][flag];
    bool tmp=false;
    int tot = y%2;
    if(x > 0 && dp(x-1,y,tot^flag^1) == 2) tmp = true;
    if(y > 0 && dp(x,y-1,tot^flag^1) == 2) tmp = true;
    // printf("%d %d %d -> %d\n",x,y,flag,tmp);
    return ans[x][y][flag] = (tmp ? 1 : 2); 
}
int main()
{
    ans[0][0][0] = 1;
    ans[0][0][1] = 2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt[2] = {0,0};
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            cnt[(x%2+2)%2]++;
        }
        printf(dp(cnt[0],cnt[1],0) == 1 ? "Alice\n" : "Bob\n");
    }  
}