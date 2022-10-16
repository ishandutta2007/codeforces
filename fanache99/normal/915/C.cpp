#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

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

int a[10], b[20];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long ca, cb;
    int db = 0, da = 0;
    scanf("%I64d%I64d", &ca, &cb);
    long long ccb = cb;
    while (ca) {
        a[ca % 10]++;
        ca /= 10;
        da++;
    }
    while (cb) {
        db++;
        b[db] = cb % 10;
        cb /= 10;
    }
    if (da < db) {
        long long answer = 0;
        for (int k = 9; k >= 0; k--)
            for (int l = 1; l <= a[k]; l++)
                answer = answer * 10 + k;
        printf("%I64d\n", answer);
        return 0;
    }
    long long answer = 0, best = 0;
    for (int i = db; i >= 1; i--) {
        int j = b[i] - 1;
        while ((j >= 1 || (i != db && j >= 0)) && !a[j])
            j--;
        if ((i == db && j == 0) || j == -1)
            if (a[b[i]] == 0)
                break;
            else {
                answer = answer * 10 + b[i];
                a[b[i]]--;
                continue;
            }
        long long temp = answer * 10 + j;
        a[j]--;
        for (int k = 9; k >= 0; k--)
            for (int l = 1; l <= a[k]; l++)
                temp = temp * 10 + k;
        a[j]++;
        best = max(best, temp);
        if (a[b[i]] == 0)
            break;
        else {
            answer = answer * 10 + b[i];
            a[b[i]]--;
        }
    }
    if (answer == ccb)
        best = answer;
    printf("%I64d\n", best);
    return 0;
}