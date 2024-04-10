#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n;

bool query(vector<int>& p0, vector<int>& p1) {    
    printf("? %d", (int)(p0.size() + p1.size()));
    for (int x : p0) printf(" %d", x);
    for (int x : p1) printf(" %d", x);
    puts("");
    fflush(stdout);

    char s[6];
    scanf("%s", s);
    return s[0] == 'Y';
}

vector<int> p0, p1, q0, q1;

void get() {
    q0.clear(); q1.clear();
    for (int i = 0; i < ((int)p0.size()) / 2; i++)
        q0.push_back(p0[i]);
    
    for (int i = 0; i < ((int)p1.size() + 1) / 2; i++)
        q1.push_back(p1[i]);
}

void ask(int x) {
    printf("! %d\n", x);
    fflush(stdout);

    char s[6];
    scanf("%s", s);
    if (s[1] == ')') exit(0);
}

int main() {
    scanf("%lld", &n);
    
    if (n == 1) {
        printf("! 1\n");
        fflush(stdout);
        return 0;
    }

    p0.resize(n);
    iota(p0.begin(), p0.end(), 1);

    while (1) {
        get();
        if (p0.size() <= 1 && p1.size() <= 2) {
            break;
        }
        if (p0.size() == 2 && p1.size() == 1) {
            q0 = p0;
            q1.clear();
        }

        bool ans = query(q0, q1);
        if (ans == true) {
            p1.clear();
            while (p0.size() > q0.size()) {
                p1.push_back(p0.back());
                p0.pop_back();
            }
            while (!q1.empty()) {
                p0.push_back(q1.back());
                q1.pop_back();
            }
        } else {
            vector<int> tmp;
            while (p0.size() > q0.size()) {
                tmp.push_back(p0.back());
                p0.pop_back();
            }
            while (p1.size() > q1.size()) {
                tmp.push_back(p1.back());
                p1.pop_back();
            }
            p0 = tmp;
            p1 = q0;
        }
    }

    if (p0.size() + p1.size() == 1) {
        for (int x : p0) ask(x);
        for (int x : p1) ask(x);
    } else if (p0.size() + p1.size() == 2) {
        for (int x : p0) ask(x);
        for (int x : p1) ask(x);
    } else {
        ask(p0[0]);
        
        q0.clear();
        q1.clear();
        q0.push_back(p1[0]);

        bool ans = query(q0, q1);
        if (ans == true) ask(p1[0]);
        else ask(p1[1]);
    }

    return 0;
}