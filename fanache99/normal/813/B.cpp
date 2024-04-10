#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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

vector<long long> v;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long x, y, l, r, xp = 1, yp;
    scanf("%I64d%I64d%I64d%I64d", &x, &y, &l, &r);
    for (int i = 0; ; i++) {
        long long now = r - xp;
        yp = 1;
        for (int j = 0; ; j++) {
            if (xp + yp >= l && xp + yp <= r)
                v.push_back(xp + yp);
            if (now / yp < y)
                break;
            yp *= y;
        }
        if (r / xp < x)
            break;
        xp *= x;
    }
    long long answer = 0;
    sort(v.begin(), v. end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    if (v.empty())
        answer = r - l + 1;
    else {
        answer = max(answer, v[0] - l);
        answer = max(answer, r - v.back());
        for (int i = 1; i < v.size(); i++)
            answer = max(answer, v[i] - v[i - 1] - 1);
    }
    printf("%I64d\n", answer);
    return 0;
}