#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, a[100011];
long long ans, nans=100000000000;
vector<int> b[100011];

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) scanf("%d", &a[i]);
    for (int i=0; i<m; i++) {
        if (i&&a[i]!=a[i-1]) b[a[i]].push_back(a[i-1]), ans+=abs(a[i]-a[i-1]);
        if (i<m-1&&a[i+1]!=a[i]) b[a[i]].push_back(a[i+1]);
    }
    bool flag=false;
    for (int i=0; i<m; i++) if (a[i]!=a[0]) flag=true;
    if (!flag) {cout << "0";
        return 0;}
    for (int i=1; i<=n; i++) {
        if (!b[i].size()) continue;
        sort(b[i].begin(), b[i].end());
        long long sum=0, sum1=0, ans1=100000000000, ans2=0;
        for (int j=0; j<b[i].size(); j++) sum+=b[i][j];
        for (int j=0; j<b[i].size(); j++) {
            long long ans3=((long long)b[i][j])*j-2*sum1+sum-b[i][j]*((long long)b[i].size()-j);
            if (ans1>ans3) ans1=ans3;
            sum1+=b[i][j];
        }
        for (int j=0; j<b[i].size(); j++) ans2+=abs(b[i][j]-i);
        nans=min(nans, ans-ans2+ans1);
    }
    cout << nans;
    return 0;
}