#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


struct card{
    int w, h, i;
    card(){}
    card(int _w, int _h, int _i){
        w = _w;
        h = _h;
        i = _i;
    }
};


bool les(const card& a, const card& b) {
    return a.w < b.w;
}


int n, w, h;
vector<card> v;
int a[100000], d[100000];


int main() {
    cin >> n >> w >> h;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > w && y > h) {
            v.push_back(card(x, y, i + 1));
        }
    }
    sort(v.begin(), v.end(), les);
    n = v.size();
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        a[i] = -1;
        for (int j = 0; j < i; j++) {
            if (v[i].w > v[j].w && v[i].h > v[j].h) {
                if (d[i] < 1 + d[j]) {
                    d[i] = 1 + d[j];
                    a[i] = j;
                }
            }
        }
    }
    int j = -1;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] > s) {
            s = d[i];
            j = i;
        }
    }
    vector<int> ans;
    if (s != 0) {
        ans.push_back(v[j].i);
        while (a[j] != -1) {
            j = a[j];
            ans.push_back(v[j].i);
        }
    }
    cout << s << endl;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}