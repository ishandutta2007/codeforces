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


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int ans=1,cnt=0;
    char t='\0',c;
    while(cin >> c)
    {
        if (t=='\0') t=c,cnt++;
        else if (t==c&&cnt<5) cnt++;
        else ans++,t=c,cnt=1;
    }
    cout << ans << endl;
    return 0;
}