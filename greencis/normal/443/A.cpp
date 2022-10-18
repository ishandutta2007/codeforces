#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int u[9999];

int main()
{
    string s;
    getline(cin,s);
    int n = 0;
    for (int i = 0; i< s.length(); ++i)
        if(s[i]>='a' && s[i]<='z' && !u[s[i]]) ++n,u[s[i]]=1;
    cout<<n;
}