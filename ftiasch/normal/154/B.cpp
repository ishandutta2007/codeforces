#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 111111;

int minDiv[N], minDivExp[N], mark[N];
bool prime[N], exists[N];

vector <int> factor(int n) {
    vector <int> result;
    while (n > 1) {
        result.push_back(minDiv[n]);
        n /= minDivExp[n];
    }
    return result;
}

void setState(int n, int s) {
    vector <int> ret = factor(n);
    for (vector <int> :: iterator iter = ret.begin(); iter != ret.end(); ++ iter) {
        mark[*iter] = s;
    }
}

int main() {
    memset(prime, 1, sizeof(prime));
    for (int i = 2; i < N; ++ i) {
        if (prime[i]) {
            minDiv[i] = i;
            for (int j = i + i; j < N; j += i) {
                prime[j] = false;
                minDiv[j] = i;
            }
        }
    }
    for (int i = 2; i < N; ++ i) {
        minDivExp[i] = 1;
        int tmp = i;
        while (tmp % minDiv[i] == 0) {
            tmp /= minDiv[i];
            minDivExp[i] *= minDiv[i];
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    memset(mark, -1, sizeof(mark));
    memset(exists, 0, sizeof(exists));
    while (m --) {
        char buffer[22];
        int x;
        scanf("%s%d", buffer, &x);
        if (*buffer == '+') {
            if (exists[x]) {
                puts("Already on");
            } else {
                vector <int> ret = factor(x);
                int found = -1;
                for (vector <int> :: iterator iter = ret.begin(); iter != ret.end(); ++ iter) {
                    if (mark[*iter] != -1) {
                        found = mark[*iter];
                    }
                }
                if (found != -1) {
                    printf("Conflict with %d\n", found);
                } else {
                    puts("Success");
                    exists[x] = true;
                    setState(x, x);
                }
            }
        } else {
            if (exists[x]) {
                exists[x] = false;
                setState(x, -1);
                puts("Success");
            } else {
                puts("Already off");
            }
        }
    }
    return 0;
}