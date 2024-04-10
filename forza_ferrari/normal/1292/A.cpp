#include<iostream>
#include<cstdio>
using namespace std;
int n,q,x,y,cnt;
bool mp[2][100001];
int main()
{
    scanf("%d%d",&n,&q);
    while(q--)
    {
        scanf("%d%d",&x,&y);
        --x;
        if(mp[x][y])
        {
            cnt-=mp[x^1][y-1]+mp[x^1][y]+mp[x^1][y+1];
            mp[x][y]^=1;
        }
        else
        {
            cnt+=mp[x^1][y-1]+mp[x^1][y]+mp[x^1][y+1];
            mp[x][y]^=1;
        }
        puts(cnt? "No":"Yes");
    }
    return 0;
}