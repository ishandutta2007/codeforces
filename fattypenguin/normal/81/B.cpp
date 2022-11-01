#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

string part[255];

char line[1000];

int main()
{
    string s,ans,last;
    gets(line);
    s = string(line);
    int len = s.size();
    bool space = false,dot = false;
    for (int i = 0;i < len;++i)
    {
        if (s[i] == ',')
        {
            if (last.size())
                ans += last;
            ans += ", ";
            space = 0;
            last = "";
        } else
        {

            if (s[i] == ' ')
        {
            space = true;
        } else
        {
            if (s[i] >= '0'  && s[i] <= '9')
            {
                if (space && last.size())
                {
                    ans += last + " ";
                    last = "";
                    space = false;
                }
                last += s[i];
            }
            else if (s[i] == '.')
            {
                if (last.size())
                {
                    ans += last;
                }
                if (ans[ans.size()-1] != ' ') ans += " ";

                    ans += "...";
                    last = "";
                    i += 2;
            }
            space = false;
        }
        }
    }
    if (last.size()) ans += last;
    if (ans[ans.size()-1] == ' ') ans = string(ans,0,ans.size()-1);
    if (ans[0] == ' ') ans = string(ans,1,ans.size()-1);
    cout << ans << endl;
    return 0;
}