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

int main()
{
    //freopen("input.txt", "r", stdin);
    string s,t;
    int a[26];
    int b[26];
    MEM(a,0);
    MEM(b,0);
    int flag1,flag2;
    flag1 = flag2 = 0;
    cin >> s >> t;
    for(int i = 0; i < s.length(); i++) a[s[i]-'a']++;
    for(int i = 0; i < t.length(); i++) b[t[i]-'a']++;
    int j = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(j == t.length()) break;
        if(t[j] == s[i])
        {
            j++;
        }
    }
    flag1 = (j==t.length());
    flag2 = 1;
    for(int i = 0; i < 26; i++)
    {
        if(b[i] > a[i])
        {
            flag2 = 0;
            break;
        }
        else if(b[i] < a[i]) flag2 = 2;
    }
    if(flag2 == 0)
    {
        cout << "need tree" << endl;
    }
    else if(flag2 == 1)
    {
        if(flag1) cout << "both" << endl;
        else  cout << "array" << endl;
    }
    else
    {
        if(flag1) cout << "automaton" << endl;
        else cout << "both" << endl;
    }
    return 0;
}