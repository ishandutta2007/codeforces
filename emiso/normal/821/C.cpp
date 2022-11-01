#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], last = 0, shouldbe = 1, ans, lastMove = 0;
set<int> stack_;
stack<int> pilha;
char s[MN]; string str;

int main() {
    scanf("%d", &n);

    for(int i=0; i<2*n; i++) {
        scanf("%s", s);
        if(s[0] == 'a') {
            scanf("%d", &a[i]);
            stack_.insert(a[i]);
            pilha.push(a[i]);
            last = a[i];

        } else if(s[0] == 'r') {
            if(last != shouldbe) {
                ans++;
                lastMove = pilha.size();
                last = *stack_.begin();
            }

            if(lastMove >= pilha.size())
                lastMove--;

            stack_.erase(last);
            pilha.pop();
            shouldbe++;

            if(pilha.empty()) continue;
            if(lastMove >= pilha.size()) {
                last = *stack_.begin();
            } else {
                last = pilha.top();
            }
        } else assert(false);
    }

    printf("%d\n", ans);
    return 0;
}

//5321RRR4RR
//1235RRR4RR
//135R2R4RRR