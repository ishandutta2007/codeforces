#include <bits/stdc++.h>

using namespace std;

int n, k, a[100010];
map<int, int> freq;
set<int> uniq;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        freq[a[i]]++;
        if(freq[a[i]] == 1) uniq.insert(a[i]);
        if(freq[a[i]] == 2) uniq.erase(a[i]);

        if(i >= k) {
            freq[a[i-k]]--;
            if(freq[a[i-k]] == 1) uniq.insert(a[i-k]);
            if(freq[a[i-k]] == 0) uniq.erase(a[i-k]);
        }

        if(i + 1 >= k) {
            if(uniq.empty()) puts("Nothing");
            else printf("%d\n", *uniq.rbegin());
        }
    }

    return 0;
}