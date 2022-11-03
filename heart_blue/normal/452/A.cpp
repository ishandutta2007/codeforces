#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1000000007;
const int N = 1e5 + 10;
vector<string> vs;
int main()
{
    //freopen("input.txt", "r", stdin);
        vs.push_back("vaporeon");
        vs.push_back("jolteon" );
        vs.push_back("flareon" );
        vs.push_back("espeon"  );
        vs.push_back("umbreon" );
        vs.push_back("leafeon" );
        vs.push_back("glaceon" );
        vs.push_back("sylveon" );
        int n;
        cin >> n;
        string str;
        cin >> str;
        for (int j = 0; j < vs.size(); j++)
        {
            if (str.length() != vs[j].length()) continue;
            int flag = 1;
            int key = -1;
            for (int i = 0; i < n; i++)
            {
                if (str[i] == '.') continue;
                if (str[i] != vs[j][i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cout << vs[j] << endl;
                break;
            }
        }
    
    
    return 0;
}