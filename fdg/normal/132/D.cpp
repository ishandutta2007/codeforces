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

char str[1000002];
int val[1000002]={0};

int check(char * s)
{
    int ans=10000,l=strlen(s);
    int val=0,b=3;
    for(int i=0;i<l;i++,b*=3)
        val+=(1<<i)*(s[i]=='1');
    for(int mask=0;mask<b;mask++)
    {
        int cval=0,cnt=0,k=mask;
        for(int i=0;i<=l;i++)
        {
            if (k%3==1) cval+=1<<i,cnt++;
            if (k%3==2) cval-=1<<i,cnt++;
            k/=3;
        }
        if (cval==val&&cnt<ans) ans=cnt;
    }
    return ans;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    strrev(str);
//  cout << check(str) << endl;
    int l=strlen(str);
    for(int i=0;i<l;i++)
        val[i]=str[i]-'0';
    int last=-1;
    for(int i=0;i<=l;i++)
    {
        if (val[i]==1)
            if (last==-1) last=i;
        if (val[i]==0)
        {
            if (last!=-1&&i-last>1)
            {
                val[i]=1;
                for(int j=last;j<i;++j)
                    val[j]=0;
                val[last]=-1;
                i--;
            }
            last=-1;
        }
    }
    int cnt=0;
    for(int i=0;i<=l;i++)
        if (val[i]!=0) cnt++;
    printf("%d\n",cnt);
    for(int i=0;i<=l;i++)
    {
        if (val[i]==1) printf("+2^%d\n",i);
        if (val[i]==-1) printf("-2^%d\n",i);
    }
    return 0;
}