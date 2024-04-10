#include <cctype>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 222222;

int n, sum[N];
char str[N];
vector <pair <int, int> > v;

bool isVowel(char c) {
    c = toupper(c);
    return c == 'A'
        || c == 'E'
        || c == 'I'
        || c == 'O'
        || c == 'U';
}

int main() {
    scanf("%s", str + 1);
    n = strlen(str + 1);
    sum[0] = 0;
    v.push_back(make_pair(sum[0], 0));
    for (int i = 1; i <= n; ++ i) {
        sum[i] = sum[i - 1];
        if (isVowel(str[i])) {
            sum[i] --;
        } else {
            sum[i] += 2;
        }
        v.push_back(make_pair(sum[i], i));
    }
    sort(v.begin(), v.end());
    int maxLength = 0;
    int minPosition = n + 1;
    for (vector <pair <int, int> > :: iterator iter = v.begin();
            iter != v.end(); ++ iter) {
        if (minPosition < iter->second) {
            maxLength = max(maxLength, iter->second - minPosition);
        }
        minPosition = min(minPosition, iter->second);
    }
    if (maxLength) {
        int maxLengthCount = 0;
        for (int i = maxLength; i <= n; ++ i) {
            if (sum[i] >= sum[i - maxLength]) {
                maxLengthCount ++;
            }
        }
        printf("%d %d\n", maxLength, maxLengthCount);
    } else {
        puts("No solution");
    }
    return 0;
}