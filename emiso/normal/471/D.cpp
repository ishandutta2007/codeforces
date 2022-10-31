#include <bits/stdc++.h>

using namespace std;

int a[200200], b[200200], z[400400];
vector<int> str;

int n, w;

void z_function(vector<int> &str, int *z) {
    for(int i = 1, L = 0, R = 0, sz = str.size(); i < sz; i++) {
        if(i > R) {
            L = R = i;
            while(R < sz && str[R] == str[R - L]) R++;
            z[i] = R - L; R--;
        }
        else {
            if(z[i - L] < R - i + 1) z[i] = z[i - L];
            else {
                L = i;
                while(R < sz && str[R] == str[R - L]) R++;
                z[i] = R - L; R--;
            }
        }
    }
}


int main() {
    scanf("%d %d", &n, &w);

    if(n < w) {
        printf("0\n");
        return 0;
    }

    if(w == 1) {
        printf("%d\n", n);
        return 0;
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < w; i++) {
        scanf("%d", &b[i]);
    }

    for(int i = 1; i < w; i++) {
        str.push_back(b[i] - b[i-1]);
    }

    str.push_back(INT_MAX);

    for(int i = 1; i < n; i++) {
        str.push_back(a[i] - a[i-1]);
    }

    z_function(str, z);
    int ans = 0;

    for(int i = w; i < str.size(); i++) {
        if(z[i] ==  w - 1) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}