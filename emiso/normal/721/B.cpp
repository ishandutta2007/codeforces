#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int freq[110],ansB, ansW, tries;

int main() {
    int n, k;
    string str;
    char s[110];
    scanf("%d %d",&n, &k);

    for(int i=0; i<n; i++) {
        scanf(" %s",s);
        str = s;
        freq[str.size()]++;
    }

    scanf(" %s",s);
    str = s;

    for(int i=1;i<str.size();i++) {
        tries += freq[i];
    }

    ansB = tries + (tries/k)*5 + 1;

    tries += freq[str.size()] - 1;
    ansW = tries + (tries/k)*5 + 1;

    printf("%d %d\n",ansB, ansW);
    return 0;
}