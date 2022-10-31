#include <bits/stdc++.h>

using namespace std;

int cc[100100][2],lA,lB,ans;

int main() {
    int n,k;
    string str;
    cin >> n >> k >> str;

    cc[1][0] = (str[0]=='a');
    cc[1][1] = (str[0]=='b');

    for(int i=1;i<str.size();i++) {
        cc[i+1][0] = cc[i][0] + (str[i]=='a');
        cc[i+1][1] = cc[i][1] + (str[i]=='b');
    }

    for(int i=0;i<=str.size();i++) {
        while(cc[i][0] - cc[lA][0] > k) lA++;
        while(cc[i][1] - cc[lB][1] > k) lB++;
        ans = max(ans,i - min(lA,lB));
    }

    printf("%d\n",ans);

    return 0;
}