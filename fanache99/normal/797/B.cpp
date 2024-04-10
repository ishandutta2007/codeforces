//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

vector<int> v;

int main() {
    int n;
    cin >> n;
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x % 2)
            v.push_back(x);
        else
            if (x > 0)
                answer += x;
    }
    sort(v.begin(), v.end());
    answer += v[v.size() - 1];
    for (int i = v.size() - 2; i >= 1; i -= 2)
        if (v[i] + v[i - 1] >= 0)
            answer += v[i] + v[i - 1];
    cout << answer << "\n";
    return 0;
}