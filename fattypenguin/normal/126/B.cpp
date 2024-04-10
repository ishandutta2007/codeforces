#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <assert.h>

using namespace std;

#define REP(i,n) for (int i = 0;i < n;++i)
#define PB push_back
#define MP make_pair

/*5.KMPHZH
//nextT
//lcpSTKMP
//KMPSi
//nextnext[i] = |TT(i,m)|2<i<m
*/
void next_function(char S[], int n, int next[])
{
    next[0] = n;
    int j = 0, k = 1;
    while(1+j<n && S[j] == S[1+j]) j++;
    next[1] = j;
    for(int i=2; i<n; ++i)
    {
        int len = k + next[k] - 1;
        int l = next[i - k];
        if(l < len - i + 1) next[i] = l;
        else
        {
            int j = max(0, len - i + 1);
            while(S[i+j] == S[j] && i + j < n) j++;
            next[i] = j;
            k = i;
        }
    }
}
void extend_kmp(char S[], int n, char T[], int m, int next[], int lcp[])
{
    next_function(T, m, next);
    int j = 0, k = 0;
    while(j<min(n, m) && T[j] == S[j]) ++j;
    lcp[0] = j;
    for(int i=1; i<n; ++i)
    {
        int len = k + lcp[k] - 1;
        int l = next[i - k];
        if(l < len - i + 1) lcp[i] = l;
        else
        {
            int j = max(0, len - i + 1);
            while(i+j<n && j<m && S[i+j]==T[j]) j++;
            lcp[i] = j;
            k = i;
        }
    }
}

char s[1000007];
int len,lcp[1000007];

int main()
{
    scanf("%s",s);
    len = strlen(s);
    next_function(s,len,lcp);
    int x = 0;
    for (int i = 1;i < len;++i)
        if (lcp[i] == len-i) x = max(x,lcp[i]-1); else x = max(x,lcp[i]);
    int ans = 0;
    for (int i = 1;i < len;++i)
        if (lcp[i] == len-i)
            if (lcp[i] <= x)
                ans = max(ans,lcp[i]);
    if (!ans) cout<<"Just a legend\n"; else cout<<string(s,0,ans)<<endl;
    return 0;
}