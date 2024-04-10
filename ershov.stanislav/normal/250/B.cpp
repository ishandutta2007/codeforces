#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int n;
    string str, a="";
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> str;
        vector<string> v;
        a="";
        for (int j=0; j<str.length(); j++) {
            if (str[j]==':') {
                if (j!=0)v.push_back(a), a="";
            } else a+=str[j];
        }
        if (a!="") v.push_back(a);
        for (int j=0; j<v.size(); j++) {
            if (v[j]!="") {
                for (int k=0; k<4-v[j].length(); k++) cout << 0;
                cout << v[j];
            }   else for (int k=0; k<9-v.size(); k++) {
                cout << "0000";
                if (k!=8-v.size()) cout << ":";
            }
            if (j!=v.size()-1) cout << ":";
        }
        cout << endl;
    }
    return 0;
}