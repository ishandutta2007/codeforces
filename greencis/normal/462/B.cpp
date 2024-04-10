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

string s;
int freq[257];
int n,k;
long long ans;

int main()
{

    cin >> n >> k >> s;
    for (int i = 0; i < s.length(); ++i) {
        ++freq[s[i]];
    }
    sort(freq,freq+257);
    reverse(freq,freq+257);
    int curidx = 0;
    while (k > 0 && curidx < 257) {
        if (k < freq[curidx]) {
            ans += (long long)k * (long long)(k);
            k = 0;
        }
        else {
            ans += (long long)freq[curidx] * (long long)(freq[curidx]);
            k -= freq[curidx];
        }
        ++curidx;
    }
    cout << ans;

    return 0;
}