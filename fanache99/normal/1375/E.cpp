#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000;

int v[1 + MAXN], p[1 + MAXN];
pair<int, int> vn[1 + MAXN];

int main(){
    //ifstream cin("input.txt");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        vn[i] = make_pair(v[i], i);
    }
    sort(vn + 1, vn + n + 1);
    for (int i = 1; i <= n; i++) {
        v[vn[i].second] = i;
        p[i] = vn[i].second;
    }
    vector<pair<int, int> > answer;
    for (int i = 1; i <= n; i++) {
        for (int j = v[i] - 1; j >= 1; j--) {
            if (p[j] > p[v[i]]) {
                answer.emplace_back(make_pair(p[v[i]], p[j]));
            }
        }
    }
    cout << answer.size() << "\n";
    for (auto it : answer) {
        cout << it.first << " " << it.second << "\n";
        swap(v[it.first], v[it.second]);
    }
    /*for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }*/
    return 0;
}