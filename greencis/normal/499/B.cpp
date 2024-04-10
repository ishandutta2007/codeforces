#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

int n,m;
string s1,s2;
map<string,pair<string,string> > mp;

int main()
{
    cin >> n >> m;
    while (m--) {
        cin >> s1 >> s2;
        mp[s1] = make_pair(s1,s2);
    }
    while (n--) {
        cin >> s1;
        if (mp[s1].first.length() > mp[s1].second.length()) cout << mp[s1].second;
        else cout << mp[s1].first;
        cout << " ";
    }
    return 0;
}