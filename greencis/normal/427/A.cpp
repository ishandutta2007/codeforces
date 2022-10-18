#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int n,a[100005],res,cur;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        if (a[i] != -1) {
            cur += a[i];
        } else {
            if (cur <= 0) ++res;
            else --cur;
        }
    }
    cout<<res;
    return 0;
}