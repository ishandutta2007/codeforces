#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char s[200200]; string str;

vector<int> seq[200200];
queue<int> e0, e1;
int nxt = 0;

int main() {
    scanf("%s", s); str = s;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0') {
            if(e1.empty()) {
                seq[nxt].push_back(i + 1);
                e0.push(nxt++);
            } else {
                int idx = e1.front(); e1.pop();
                seq[idx].push_back(i + 1);
                e0.push(idx);
            }
        }
        else {
            if(e0.empty()) {
                printf("-1\n"); return 0;
            } else {
                int idx = e0.front(); e0.pop();
                seq[idx].push_back(i + 1);
                e1.push(idx);
            }
        }
    }

    for(int i = 0; i < nxt; i++) {
        if(seq[i].size() % 2 == 0) {
            printf("-1\n"); return 0;
        }
    }

    printf("%d\n", nxt);
    for(int i = 0; i < nxt; i++) {
        printf("%d", seq[i].size());
        for(int x : seq[i])
            printf(" %d", x);
        puts("");
    }

    return 0;
}