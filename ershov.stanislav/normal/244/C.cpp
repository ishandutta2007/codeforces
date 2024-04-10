#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    set<int> s, res, s2;
    int n, a;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        s2 = set<int>();
        for (set<int>::iterator j=s.begin(); j!=s.end(); j++) {
            s2.insert((*j)|a);
        }
        s2.insert(a);
        s = s2;
        res.insert(s.begin(), s.end());
    }
    cout << res.size();
    return 0;
}