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
typedef long long ll;
typedef long double ld;

int n,k,a[9999],b[9999];
map<int, vector<int> > mp;
map<int,int> midxs;
vector<int> v,ans;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin>>a[i] >> b[i];
        mp[a[i]].push_back(b[i]);
        mp[b[i]].push_back(a[i]);
        midxs[a[i]] = 1;
        midxs[b[i]] = 1;
    }

    for (map<int,int>::iterator it = midxs.begin(); it != midxs.end(); ++it)
        v.push_back(it->first);

    for (int i = 0; i < v.size(); ++i) {
        ans.clear();
        for (int j = 0; j < v.size(); ++j) {
            if (i == j) continue;
            if (find(mp[v[i]].begin(), mp[v[i]].end(), v[j]) != mp[v[i]].end()) continue;
            vector<int> v1 = mp[v[i]], v2 = mp[v[j]];
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            int cnt = 0, p1 = 0, p2 = 0;
            while (p1 < v1.size() && p2 < v2.size()) {
                if (v1[p1] == v2[p2]) ++cnt;

                if (v1[p1] < v2[p2]) ++p1;
                else ++p2;
            }

            if (cnt * 100 >= k * v1.size()) ans.push_back(v[j]);
        }
        cout << v[i] << ": " << ans.size() << " ";
        for (int j = 0; j < ans.size(); ++j) cout << ans[j] << " ";
        cout << endl;
    }


    return 0;
}