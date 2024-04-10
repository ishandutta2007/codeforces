#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T, typename cmp = less<T>>
using oset = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

oset<int> occur[26];

int k, n, p, dont[200020];
string str, t;
char s[110];

int main() {
    scanf("%d %s", &k, s); str = s;
    for(int i = 0; i < k; i++) {
        for(char c : str) {
            occur[c-'a'].insert(t.size());
            t += c;
        }
    }

    scanf("%d", &n);
    while(n--) {
        char c;
        scanf("%d %c", &p, &c);

        auto jon = occur[c-'a'].find_by_order(p-1);
        dont[*jon] = 1;
        occur[c-'a'].erase(jon);
    }

    for(int i = 0; i < t.size(); i++)
        if(!dont[i])
            printf("%c", t[i]);
    puts("");
    return 0;
}