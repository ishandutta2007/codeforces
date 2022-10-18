#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int get(char * s)
{
    int tm=atoi(s+1)%12*60+atoi(s+4);
    if (s[7]=='p') tm+=12*60;
    return tm;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,tot=0,cnt=1,kol=0;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char s[200];
        gets(s);
        int cur=get(s);
        if (cur>tot)
        {
            tot=cur; kol=1;
        }
        else
        {
            if (tot==cur)
            {
                if (kol<10) kol++;
                else cnt++,kol=1;
            }
            else
            {
                cnt++;
                tot=cur; kol=1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}