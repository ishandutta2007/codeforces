#include <bits/stdc++.h>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main() {
    int n,flag = 0;
    int used[] = {0,0,0,0,0};
    string str;

    scanf("%d",&n);

    cin >> str;
    for(int i=0;i<str.size();i++) {
        char d = str[i];
        if(d == '1' || d == '2' || d == '3') used[0] = 1;
        if(d == '3' || d == '6' || d == '9') used[1] = 1;
        if(d == '7' || d == '0' || d == '9') used[2] = 1;
        if(d == '1' || d == '4' || d == '7') used[3] = 1;
        if(d == '0') used[4] = 1;
    }

    if(used[0] && used[1] && used[2] && used[3]) flag = 1;
    else if(used[4] && used[0]) flag = 1;

    if(flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}