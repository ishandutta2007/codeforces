#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int dp[222][102][52][2],l;
char txt[103]={0};

int rec(int pos,int step,int left,int sgn)
{
    if (step==l)
    {
        if (left&1) return 0;
        return labs(pos-100);
    }
    if (dp[pos][step][left][sgn]!=-1) return dp[pos][step][left][sgn];
    int way=sgn==0 ? 1 : -1;
    int ans=0;
    if (txt[step]=='F') ans=max(ans,rec(pos+way,step+1,left,sgn));
    if (txt[step]=='T') ans=max(ans,rec(pos,step+1,left,sgn^1));
    if (left)
    {
        if (txt[step]=='T') ans=max(ans,rec(pos+way,step+1,left-1,sgn));
        if (txt[step]=='F') ans=max(ans,rec(pos,step+1,left-1,sgn^1));
    }
    return dp[pos][step][left][sgn]=ans;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(txt);
    l=strlen(txt);
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << rec(100,0,n,0) << endl;
    return 0;
}