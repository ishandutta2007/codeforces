#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
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
using namespace std;
int main ()
{
    string str;
    while(cin >> str)
    {
        string out = "";
        vector <string> v;
        //str = "WUBWUBWUBWUBUUU";
        for(int i = 0 ; i + 2 < str.size(); i++)
        {
            if(str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B')
            {
                str[i] = ' ';
                str[i+1] = ' ';
                str[i+2] = ' ';
                //i += 2;
            }
        }
        for(int i = 0 ; i < str.size() ; i++)
        {
            if(str[i] != ' ' && v.size() == 0)
            {
                out += str[i];
            }
            else if(str[i] != ' ')
            {
                out += str[i];
            }
            else if(str[i] == ' ')
            {
                if(out != "")
                {
                v.push_back(out);
                out = "";
                }
            }
        }
        if(out != "")
        {
            v.push_back(out);
            out = "";
        }
        for(int i = 0 ; i < v.size() ; i++)
        {
            cout << v[i];
            if(i != v.size()-1)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}