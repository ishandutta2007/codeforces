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
#include <map>
#include <set>


using namespace std;


#define M 1000000009 
#define P 424243


int n;
unordered_map<string, vector<string> >  m;
map<vector<string>, vector<string> >  m1;


int main() {
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string a;
        string b;
        string c;
        int cnt = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == '/') {
                cnt++;
            }
            if (cnt >= 3) {
                a = b;
                for (int k = j; k < (int)s.size(); k++) {
                    c += s[k];
                }
                break;
            }
            b += s[j];
        }
        if (cnt < 3) {
            a = s;
            c = "";
        }
        m[a].push_back(c);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    vector<vector<string> > v1;
    for (int i = 0; i < (int)v.size(); i++) {
        sort(m[v[i]].begin(), m[v[i]].end());
        m[v[i]].resize(distance(m[v[i]].begin(), unique(m[v[i]].begin(), m[v[i]].end())));
        m1[m[v[i]]].push_back(v[i]);
        v1.push_back(m[v[i]]);
    }
    sort(v1.begin(), v1.end());
    v1.resize(distance(v1.begin(), unique(v1.begin(), v1.end())));
    int k = 0;
    for (int i = 0; i < (int)v1.size(); i++) {
        if ((int)m1[v1[i]].size() >= 2) {
            k++;
        }
    }
    cout << k << endl;
    for (int i = 0; i < (int)v1.size(); i++) {
        if ((int)m1[v1[i]].size() >= 2) {
            for (int j = 0; j < (int)m1[v1[i]].size(); j++) {
                cout << m1[v1[i]][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}