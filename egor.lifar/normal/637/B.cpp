#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;

int n;
unordered_map<string, int> m;
set<pair<int, string> > s;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (m.find(a) == m.end()) {
            m[a] = i;
            s.insert(make_pair(-m[a], a));
        } else {
            s.erase(make_pair(-m[a], a));
            m[a] = i;
            s.insert(make_pair(-m[a], a));
        }
    }    
    set<pair<int, string> >::iterator it = s.begin();
    while (it != s.end()) {
        cout << (*it).second << endl;
        it++;
    }
    return 0;
}