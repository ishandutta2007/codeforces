#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>   
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <set>
#include <memory.h>
#include <cstring>
#include <map>
#include <time.h>
#include <string>
#include <iterator>
using namespace std;
//#pragma comment(linker, "/STACK:9999999999")

map<string, int> mp;
string s1, s2, s3;
int n;

int main()
{
    mp["polycarp"] = 1;
    cin >> n;
    int ans = 1;
    while (n--) {
        cin >> s1 >> s2 >> s3;
        for (int i = 0; i < s1.size(); ++i)
            if (s1[i] < 'a') s1[i] += 32;
        for (int i = 0; i < s3.size(); ++i)
            if (s3[i] < 'a') s3[i] += 32;
        mp[s1] = max(mp[s1], mp[s3] + 1);
        ans = max(ans, mp[s1]);
    }
    cout << ans;
    return 0;
}