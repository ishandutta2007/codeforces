#include <bits/stdc++.h>

using namespace std;

char s[100010];
string str;

int idk, q0, q1, ans[4];

void calc(int n0, int n1) {
    if(q1 + n1 >= 2 + q0 + n0) {
        ans[3] = 1;
        return;
    }
    if(q1 + n1 + 1 <= q0 + n0) {
        ans[0] = 1;
        return;
    }

    for(int t = 0; t < 2; t++) {
        queue<int> i0, i1;
        int tmp0 = n0, tmp1 = n1;
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            if(c == '0') i0.push(i);
            if(c == '1') i1.push(i);
            if(c == '?') {
                if(!t) {
                    if(tmp0) {
                        i0.push(i);
                        tmp0--;
                    } else {
                        i1.push(i);
                        tmp1--;
                    }
                } else {
                    if(tmp1) {
                        i1.push(i);
                        tmp1--;
                    } else {
                        i0.push(i);
                        tmp0--;
                    }
                }
            }
        }

        while(i0.size() + i1.size() > 2) {
            if(!i1.empty()) i1.pop();
            if(i0.size() + i1.size() == 2) break;
            if(!i0.empty()) i0.pop();
        }

        if(i0.empty()) ans[3] = 1;
        else if(i1.empty()) ans[0] = 1;
        else {
            int p1 = i1.front(), p0 = i0.front();
            if(p1 < p0) ans[2] = 1;
            else ans[1] = 1;
        }
    }
}

int main() {
    scanf("%s", s);
    str = s;

    for(char c : str) {
        if(c == '?') idk++;
        if(c == '0') q0++;
        if(c == '1') q1++;
    }

    for(int i = 0; i <= idk; i++)
        calc(i, idk-i);

    if(ans[0]) puts("00");
    if(ans[1]) puts("01");
    if(ans[2]) puts("10");
    if(ans[3]) puts("11");
    return 0;
}