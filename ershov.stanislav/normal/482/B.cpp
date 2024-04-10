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

int n, m, c[50], cc[50][111111], s[50][111111], a[111111], cnt[50], ll[111111], rr[111111], qq[111111];
bool flag=true;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int l, r, q;
        cin >> l >> r >> q;
        ll[i]=l;
        rr[i]=r;
        qq[i]=q;
        for (int j=0; j<30; j++) if (q&(1<<j)) s[j][l]++, s[j][r+1]--;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<30; j++) c[j]+=s[j][i];
        for (int j=0; j<30; j++) if (c[j]) a[i]+=1<<j, cnt[j]++;
        for (int j=0; j<30; j++) cc[j][i]=cnt[j];
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<30; j++) {
            if (!(qq[i]&(1<<j))) {
                if (cc[j][rr[i]]-cc[j][ll[i]-1]==rr[i]+1-ll[i]) flag=false;
            }
        }
    }
    if (flag) {
        cout << "YES" << endl;
        for (int i=1; i<=n; i++) cout << a[i] << ' ';
    } else cout << "NO"<< endl;
	return 0;
}