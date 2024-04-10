#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>
#include <map>

#define ll long long

using namespace std;

int color[1002];

int repr(int x)
{
    if (color[x]!=x) color[x]=repr(color[x]);
    return color[x];
}

void join(int x,int y)
{
    color[repr(x)]=repr(y);
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    char s[1002]={0};
    gets(s);
    int l=strlen(s),cnt[26]={0};
    for(int i=1;i<=l;i++) color[i]=i;
    for(int i=0;i<l;i++) cnt[s[i]-'a']++;
    for(int i=2;i<=l;i++)
    {
        bool ok=true;
        for(int j=2;j*j<=i;j++)
            if (i%j==0)
            {
                ok=false;
                break;
            }
        if (ok)
        {
            int ii=l/i;
            for(int j=1;j<=ii;j++)
                join(i,j*i);
        }
    }
    int ind=-1,my=0;
    for(int i=1;i<=l;i++)
    {
        int cnt1=0;
        for(int j=1;j<=l;j++)
            if (repr(j)==i) cnt1++;
        if (cnt1>1||cnt1==1&&ind==-1) ind=i,my=cnt1;
    }
    if (ind!=-1)
    {
        for(int i=0;i<26;i++)
        {
            if (cnt[i]>=my)
            {
                printf("YES\n");
                for(int j=1;j<=l;j++)
                    if (repr(j)==ind) s[j-1]=i+'a',cnt[i]--;
                for(int j=1;j<=l;j++)
                    if (repr(j)!=ind)
                    {
                        for(int t=0;t<26;t++)
                            if (cnt[t])
                            {
                                s[j-1]=t+'a',cnt[t]--;
                                break;
                            }
                    }
                cout << s << endl;
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}