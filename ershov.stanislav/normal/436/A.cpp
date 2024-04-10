#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, x, t[2022], h[2022], m[2022], h2[2022];
vector<pair<int, int> > a1, a2;
int ans1, ans2;

int main() {
    cin >> n >> x;
    for (int i=0; i<n; i++) {
        cin >> t[i] >> h[i] >> m[i];
        h2[i]=h[i];
    }
    for (int i=0, tt=0, hh=x; i<n; i++, ans1=i) {
        int maxm=0, maxi=0;
        for (int j=0; j<n; j++) if (t[j]==tt&&h[j]<=hh&&m[j]>maxm) maxm=m[j], maxi=j;
        if (!maxm) {
            break;
        }
        h[maxi]=100000000;
        hh+=maxm;
        tt^=1;
    }
    for (int i=0; i<n; i++) h[i]=h2[i];
    for (int i=0, tt=1, hh=x; i<n; i++, ans2=i) {
        int maxm=0, maxi=0;
        for (int j=0; j<n; j++) if (t[j]==tt&&h[j]<=hh&&m[j]>maxm) maxm=m[j], maxi=j;
        if (!maxm) {
            break;
        }
        h[maxi]=100000000;
        hh+=maxm;
        tt^=1;
    }
    cout << max(ans1, ans2);
	return 0;
}