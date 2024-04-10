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

using namespace std;

int rev(int x)
{
    int res=0;
    for(int i=0;i<8;i++)
        if (x&(1<<i)) res|=1<<(7-i);
    return res;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    char txt[103]={0};
    gets(txt);
    int l=strlen(txt),last=0;
    for(int i=0;i<l;i++)
    {
        int cur=rev(txt[i]);
        last=rev(last);
        cout << (last-cur+256)%256 << endl;
        last=txt[i];
    }
    return 0;
}