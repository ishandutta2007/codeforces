#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

int num[33][33];
int have[5555][33];

string s;

int main()
{
    cin >> s;
    double p = 0;
    FOR (ch,0,'z'-'a'+1)
    {
        int num = 0;
        FOR (i,0,5555) FOR (j,0,33) have[i][j] = 0;
        FOR (i,0,s.size())
        if (s[i]-'a' == ch)
        {
            num++;
            FOR (j,1,s.size())
                have[j][s[(i+j)%s.size()]-'a']++;
        }
        if (num)
        {
            int z = 0;
            int ap = 0;
            FOR (i,1,s.size())
            {
                int zz = 0;
                FOR (j,0,'z'-'a'+1) zz += (have[i][j] == 1);
                z = max(z,zz);
            }
            p += z;
        }
    }
    printf("%.11lf",(p+.0)/s.size());
    return 0;
}