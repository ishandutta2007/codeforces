//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

vector<pair<int, int> > v;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int value;
        string type;
        cin >> value >> type;
        if (type[0] == 'U')
            v.push_back(make_pair(value, 0));
        else
            v.push_back(make_pair(value, 1));
    }
    sort(v.begin(), v.end());
    int answer = 0;
    long long cost = 0;
    for (auto &it : v)
        if (it.second == 0) {
            if (a) {
                cost += it.first;
                answer++;
                a--;
            }
            else
                if (c) {
                    cost += it.first;
                    answer++;
                    c--;
                }
        }
        else
            if (b) {
                cost += it.first;
                answer++;
                b--;
            }
            else
                if (c) {
                    cost += it.first;
                    answer++;
                    c--;
                }
    cout << answer << " " << cost << "\n";
    return 0;
}