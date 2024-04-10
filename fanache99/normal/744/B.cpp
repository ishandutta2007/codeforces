//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000;
const int INF = 1000000000;

int answer[1 + MAXN];
vector<int> first, second;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        answer[i] = INF;
    for (int i = 0; (1 << i) <= n; i++) {
        first.clear();
        second.clear();
        for (int j = 1; j <= n; j++)
            if (j & (1 << i))
                second.push_back(j);
            else
                first.push_back(j);
        cout << first.size() << "\n";
        for (auto &it : first)
            cout << it << " ";
        cout << "\n";
        cout.flush();
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (j & (1 << i))
                answer[j] = min(answer[j], x);
        }
        cout << second.size() << "\n";
        for (auto &it : second)
            cout << it << " ";
        cout << "\n";
        cout.flush();
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (!(j & (1 << i)))
                answer[j] = min(answer[j], x);
        }
    }
    cout << "-1\n";
    for (int i = 1; i <= n; i++)
        cout << answer[i] << " ";
    cout << "\n";
    cout.flush();
    return 0;
}