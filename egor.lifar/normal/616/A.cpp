#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string.h>


using namespace std;


char c[1000001];


int main() {
    scanf("%s\n", c);
    string a;
    a = string(c);
    scanf("%s", c);
    string b;
    b = string(c);
    string d;
    bool t = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (!t && a[i] == '0') {
            continue;
        }
        t = 1;
        d += a[i];
    }
    a = d;
    t = 0;
    d.clear();
    for (int i = 0; i < (int)b.size(); i++) {
        if (!t && b[i] == '0') {
            continue;
        }
        t = 1;
        d += b[i];
    }
    b = d;
    if (a.size() > b.size()) {
        cout << ">" << endl;
        return 0;
    }
    if (a.size() < b.size()) {
        cout << "<" << endl;
        return 0;
    }
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] > b[i]) {
            cout << ">" << endl;
            return 0;
        }
        if (a[i] < b[i]) {
            cout << "<" << endl;
            return 0;
        }
    }
    cout << "=" << endl;
    return 0;
}