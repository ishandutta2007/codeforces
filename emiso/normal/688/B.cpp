#include <bits/stdc++.h>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main() {
    string str, ans, ansb;
    char ent[100100];
    scanf("%s",ent);
    str = ent;
    for(int i=0;i<str.size();i++) {
        ans += str[i];
        ansb = str[i] + ansb;
    }
    ans += ansb;
    printf("%s\n",ans.c_str());
    return 0;
}