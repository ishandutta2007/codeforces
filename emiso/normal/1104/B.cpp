#include <bits/stdc++.h>

using namespace std;

char s[100100]; string str;
int ans;

int main() {
    scanf("%s", s); str = s;

    stack<char> st;
    for(int c : str) {
        if(!st.empty() && c == st.top()) {
            st.pop();
            ans++;
        }
        else st.push(c);
    }

    puts(ans % 2 ? "Yes" : "No");
    return 0;
}