#include <bits/stdc++.h>

using namespace std;

int n, x;
stack<int> st;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if(st.empty() || st.top() != (x % 2)) st.push(x % 2);
        else st.pop();
    }
    printf("%s\n", (st.size() < 2) ? "YES" : "NO");
    return 0;
}