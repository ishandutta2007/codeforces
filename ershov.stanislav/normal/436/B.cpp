#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m, k, a[2022][2022], p[2022];

int main() {
    cin >> n >> m >> k;
    string s;
    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<m; j++) a[i][j]=s[j];
    }
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        if (j-i>=0&&a[i][j-i]=='R') p[j]++;
        if (j+i<m&&a[i][j+i]=='L') p[j]++;
        if (2*i<n&&a[i*2][j]=='U') p[j]++;
    }
    for (int i=0; i<m; i++) cout << p[i] << ' ';
	return 0;
}