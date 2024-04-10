#include <bits/stdc++.h>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main() {
    int n,d,ans = 0,cur = 0,flag;
    string str;

    scanf("%d %d ",&n,&d);
    for(int i=0;i<d;i++) {
        cin >> str;
        flag = 0;
        for(int j=0;j<str.size();j++) {
            if(str[j] == '0') flag = 1;
        }
        if(flag) cur++;
        else {
            ans = max(ans, cur);
            cur = 0;
        }
    }

    ans = max(ans, cur);
    cur = 0;

    printf("%d\n",ans);

    return 0;
}