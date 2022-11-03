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
ifstream fin("ab.txt");
#define MEM(x) (memset((x),0,sizeof((x))))
#define MIN(x,y) ((x)<(y)?(x):(y))
string str;
int n,k;


int main()
{
    string str1,str2;
    cin >> n >> k >> str;
    int s = 0;
    int t = 0;
    int ans = 0;
    if(k == 2)
    {
        char a = 'A';
        char b = 'B';
        int ans1,ans2;
        ans1 = ans2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] != a) ans1++;
            else ans2++;
            swap(a,b);
        }
        a = 'A';
        b = 'B';
        if(ans1 > ans2) swap(a,b);
        cout << MIN(ans1,ans2) << endl;
        for(int i = 0; i < n; i++)
        {
            cout << a;
            swap(a,b);
        }
        cout << endl;
    }
    else
    {
        str = "1" + str + "1";
    
        for(int i = 1; i <= n+1; i++)
        {
            if(str[i] != str[i-1])
            {
                t = i-1;
                if(s != t)
                {
                    if((t - s) %2 == 0)
                    {
                        char c;
                        if(str[t] == 'A') c = 'B';
                        else c = str[t] - 1;
                        for(int j = s + 1; j <= t; j+=2)
                        {
                            str[j] = c;
                            ans ++;
                        }
                        s = t+1;
                    }
                    else
                    {
                        if(s == 1)
                        {
                            char c;
                            if(str[t] == 'A') c = 'B';
                            else c = str[t] - 1;
                            for(int j = s; j <= t; j+=2)
                            {
                                str[j] = c;
                                ans ++;
                            }
                            s = t+1;
                        }
                        else
                        {
                            char c;
                        
                            for(char cp = 'A'; cp <= char(k+'A'); cp++)
                            {
                                if(cp != str[t] && cp != str[t+1])
                                {
                                    c = cp;
                                    break;
                                }
                            }
                            for(int j = s+1; j <= t; j+=2)
                            {
                                str[j] = c;
                                ans ++;
                            }
                            s = t+1;
                        }
                    }
                }
                else s++;
            }
        }
        cout << ans << endl;
        for(int i = 1; i <= n; i++) cout << str[i];
        cout << endl;
    }

    return 0;
}