#include <bits/stdc++.h>

using namespace std;

int n, x, f[200020], L, R, ans;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        f[x]++;
        if(ans < f[x]) {
            ans = f[x];
            L = R = x;
        }
    }

    for(int i = 1; i < 200002;) {
        if(!f[i]) i++;
        else if(!f[i+1]) i++;
        else {
            int j = i + 1, tmp = f[i];
            while(f[j] > 1) tmp += f[j++];
            if(f[j] == 0) j--;
            else tmp += f[j];

            if(tmp > ans) {
                ans = tmp;
                L = i;
                R = j;
            }
            i = j;
        }
    }

    vector<int> seq;
    for(int i = L; i <= R; i++) {
        seq.push_back(i);
        f[i]--;
    }
    for(int i = R-1; i > L; i--) {
        seq.push_back(i);
        f[i]--;
    }

    printf("%d\n", ans);
    for(int i = 0; i < seq.size(); i++) {
        printf("%d ", seq[i]);
        while(f[seq[i]]) {
            printf("%d ", seq[i]);
            f[seq[i]]--;
        }
    }

    return 0;
}