#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n, flag = 1, p[110];
    char s[110];

    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d ",&p[i]);
    }

    for(int i=0; i<n; i++) {
        string str;
        getline(cin, str);

        int co=0;

        for(int i=0; i<str.size();i++) {
            if(str[i] == 'a' || str[i] == 'e' ||
               str[i] == 'i' || str[i] == 'o' ||
               str[i] == 'u' || str[i] == 'y' ) co++;
        }

        if(co != p[i]) flag = 0;
    }

    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}