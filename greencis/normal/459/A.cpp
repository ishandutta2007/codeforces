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

int xa,ya,xb,yb,side;

int main()
{
    cin>>xa>>ya>>xb>>yb;
    side = max(abs(ya-yb),abs(xa-xb));
    if (xa == xb) {
        cout << xa + side << " " << ya << " "<< xa + side << " " << yb << " ";
    }else if (ya==yb) {
        cout << xa << " " << ya + side << " "<< xb  << " " << yb+ side << " ";
    }else if (abs(xa-xb) == abs(ya-yb)){cout << xa << " " << yb << " "<< xb  << " " << ya << " ";}
    else{cout << -1;return 0;}
}