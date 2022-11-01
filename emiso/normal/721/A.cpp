#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n,ans=0,co=0;
    char s[110];
    vector<int> resp;
    scanf("%d %s",&n, s);

    for(int i=0; i<n; i++) {
        if(s[i] == 'W') {
            if(co) {
                resp.push_back(co);
            }
            co = 0;
        }
        else {
            co++;
        }
    }

    if(co) {
        resp.push_back(co);
    }

    printf("%d\n",resp.size());
    for(int i=0;i<(int)resp.size(); i++) {
        printf("%d ",resp[i]);
    }
    return 0;
}