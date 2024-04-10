#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define REP(i,n) for (int i = 0;i < n;++i)

int f[1000007],g[1000007];
char s[1000007];

int main()
{
    scanf("%s",s);
    int n = strlen(s);
    for (int i = n;i > 0;--i) s[i] = s[i-1];
    s[0] = '0';
    ++n;
    s[n] = 0;
    f[0] = 0x7f7f7f7f,g[0] = 0;
    for (int i = 0;i < n;++i)
        if (s[i] == '0')
        {
            f[i+1]= min(f[i]+1,g[i]+1);
            g[i+1]= g[i];
        }
        else
        {
            f[i+1] = f[i];
            g[i+1] = min(f[i]+1,g[i]+1);
        }
    cout << g[n] << endl;
    vector<int> ans;
    int now = 1;
    for (int i = n-1;i >= 0;--i)
        if (s[i] == '0')
        {
            if (now == 0)
            {
                if (f[i] < g[i])
                {
                    ans.push_back(-(n-i));
                    now = 0;
                }
                else
                {
                    ans.push_back((n-i));
                    now = 1;
                }
            }
        }
        else
        {
            if (now == 1)
            {
                if (f[i] < g[i])
                {
                    ans.push_back(-(n-i));
                    now = 0;
                }
                else
                {
                    ans.push_back((n-i));
                    now = 1;
                }
            }
        }
    for (int i = 0;i < ans.size();++i)
        printf("%c2^%d\n",ans[i]>0?'+':'-',ans[i]>0?ans[i]-1:-ans[i]-1);
    return 0;
}