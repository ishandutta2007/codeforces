#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 200000;

int c[1 + MAXN], t[1 + MAXN];
vector<pair<int, int> > smaller, bigger;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, need;
    scanf("%d %d", &n, &need);
    double answer = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    long long sumBig = 0, sumSmall = 0;
    for (int i = 1; i <= n; i++)
        if (t[i] == need)
            answer += c[i];
        else
            if (t[i] > need) {
                sumBig += 1LL * (t[i] - need) * c[i];
                bigger.push_back(make_pair(t[i], c[i]));
            }
            else {
                sumSmall += 1LL * (need - t[i]) * c[i];
                smaller.push_back(make_pair(-t[i], c[i]));
            }
    long long limit = min(sumBig, sumSmall);
    long long sum = 0;
    sort(bigger.begin(), bigger.end());
    for (auto &it : bigger) {
        int t0 = it.first, c0 = it.second;
        sum += 1LL * (t0 - need) * c0;
        answer += c0;
        if (sum > limit) {
            answer -= 1.0 * (sum - limit) / (t0 - need);
            break;
        }
    }
    sum = 0;
    sort(smaller.begin(), smaller.end());
    for (auto &it : smaller) {
        int t0 = -it.first, c0 = it.second;
        sum += 1LL * (need - t0) * c0;
        answer += c0;
        if (sum > limit) {
            answer -= 1.0 * (sum - limit) / (need - t0);
            break;
        }
    }
    printf("%.15f\n", answer);
    return 0;
}