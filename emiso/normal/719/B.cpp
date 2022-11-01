#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int pd[100100][2];
int co[2], wrong[2], ans1, ans2;

int main() {
    int n;
    char s[100100];
    scanf("%d %s",&n, s);

    for(int i=0;i<n;i++) {
        if(s[i] == 'b')
            co[0]++;
        else co[1]++;
    }

    for(int i=0;i<n;i++) { // brbrbr
        if(i % 2 == 0 && s[i] == 'r') wrong[1]++;
        if(i % 2 == 1 && s[i] == 'b') wrong[0]++;
    }
    ans1 = max(wrong[0], wrong[1]);

    wrong[0] = wrong[1] = 0;
    for(int i=0;i<n;i++) { // rbrbrb
        if(i % 2 == 0 && s[i] == 'b') wrong[0]++;
        if(i % 2 == 1 && s[i] == 'r') wrong[1]++;
    }
    ans2 = max(wrong[0], wrong[1]);

    printf("%d\n",min(ans1, ans2));
    return 0;
}