//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const long long INF = 1000000000000000000LL;
const int MAXN = 500;
const int SQRT = 40000;

int v[1 + MAXN];

long long Count(int n, int x) {
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        int y = v[i] / (x + 1);
        if (v[i] % (x + 1))
            y++;
        if (x * y > v[i])
            return INF;
        answer += y;
    }
    return answer;
}

int main() {
    int n;
    long long answer = INF;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= SQRT && i <= v[1]; i++)
        answer = min(answer, Count(n, i));
    for (int i = 1; i <= v[1]; i++) {
        int x = v[1] / i;
        if (x <= SQRT)
            break;
        answer = min(answer, Count(n, x));
        if (v[1] % i == 0)
            answer = min(answer, Count(n, x - 1));
    }
    cout << answer << "\n";
    return 0;
}