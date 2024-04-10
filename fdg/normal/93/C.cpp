#include <iostream>
#include <vector>
#include <string>

#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

struct state{
    int what,f,s,a,b,k,x,y;
};

int dp[256][256];
state back[256][256];


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    if (n==1)
    {
        cout << 0 << endl;
        return 0;
    }
    memset(dp,1000000,sizeof(dp));
//  for(int i=0;i<=n;i++) dp[0][i]=dp[i][0]=0;
    dp[0][0]=0;
    for(int i=0;i<=2*n;i++)
    {
        for(int j=max(i-n,0);j<=i&&j<=n;j++)
        {
            int x=j,y=i-j;
            int nums[]={1,x,y};
            for(int what=0;what<2;what++)
            {
                for(int f=0;f<2;f++)
                {
                    for(int s=(f==0);s<2;s++)
                    {
                        for(int a=0;a<3;a++)
                        {
                            for(int b=0;b<3;b++)
                            {
                                for(int k=0;k<=3;k++)
                                {
                                    int st[2]={x,y};
                                    st[what]=f*nums[a]+s*(1<<k)*nums[b];
                                    if (st[0]<=n&&st[1]<=n&&dp[st[0]][st[1]]>dp[x][y]+1)
                                    {
                                        dp[st[0]][st[1]]=dp[x][y]+1;
                                        state pr={what,f,s,a,b,k,x,y};
                                        back[st[0]][st[1]]=pr;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int res=5000000,x,y;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if (i==n||j==n)
            {
                if (dp[i][j]<res)
                {
                    res=dp[i][j];
                    x=i; y=j;
                }
            }
        }
    }
    cout << res << endl;
    vector <string> ans;
    char reg[3][4]={"eax","ebx","ecx"};
    while(x!=0||y!=0)
    {
        string str="lea ";
        if (back[x][y].what==0) str+="ebx, [";
        else str+="ecx, [";
        if (back[x][y].f!=0) str+=reg[back[x][y].a];
        if (back[x][y].s!=0)
        {
            if (back[x][y].f!=0) str+=" + ";
            if (back[x][y].k>0)
            {
                str+=(1<<back[x][y].k)+'0';
                str+="*";
            }
            str+=reg[back[x][y].b];
        }
        str+="]";
        ans.push_back(str);
        int nx=back[x][y].x,ny=back[x][y].y;
        x=nx; y=ny;
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i] << endl;
    return 0;
}