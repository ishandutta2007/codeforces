//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;

int p[1 + MAXN], b[1 + MAXN];
bool seen[1 + MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int answer = 0;
    for (int i = 1; i <= n; i++)
        if (!seen[i]) {
            answer++;
            int x = p[i];
            while (x != i) {
                seen[x] = true;
                x = p[x];
            }
            seen[x] = true;
        }
    if (answer == 1)
        answer--;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += b[i];
    answer += (1 - sum % 2);
    cout << answer << "\n";
    return 0;
}