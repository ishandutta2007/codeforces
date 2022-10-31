#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

char s[5000], p[5000];
int slen, plen, dp[2100][2100];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif
    cin >> s >> p;
    slen=(int)strlen(s);
    plen=(int)strlen(p);
    if (plen > slen) {
        for (int i=0; i<=slen; i++) cout << "0 ";
        return 0;
    }
    for (int i=1; i<=slen; i++) for (int j=slen-plen+1; j<=slen; j++) dp[j][i]=1e8;
    for (int i=slen-plen; i>=0; i--) {
        bool flag=true;
        if (s[i]==p[0]) {
            int j=1, k=i+1;
            if (plen>1) for (; k<slen; k++)  {
                if (s[k]==p[j]) j++;
                if (j==plen) break;
            }
            else k=i;
            if (j==plen) {
                flag = false;
                for (int m=1; m<=slen; m++) dp[i][m]=min(dp[i+1][m], dp[k+1][m-1]+(k+1-i)-plen);
            }
        }
        if (flag) {
            for (int j=0; j<=slen; j++) dp[i][j]=dp[i+1][j];
        }
    }
    int maxj=0;
    for (int i=0; i<=slen; i++) if (dp[0][i]<1e7) maxj=i;
    for (int i=0, j=0; i<=dp[0][maxj]; i++) {
        while (j<slen&&dp[0][j+1]<=i) j++;
        cout << j << ' ';
    }
    for (int i=dp[0][maxj]+1; i<=slen-plen*maxj; i++) cout << maxj << ' ';
    for (int i=slen-plen*maxj+1; i<=slen; i++) cout << (slen-i)/plen << ' ';
    return 0;
}