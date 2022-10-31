#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct num {int a; int i; };

bool compare(num a, num b) {return (a.a < b.a); }

int main()
{
    int n, h;
    vector<num> a;
    cin >> n >> h;
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].a;
        a[i].i = i;
    }
    sort(a.begin(), a.end(), compare);
    if (n == 2) cout << 0 << endl << "1 1";
    else {
        int try1, try2;
        try1 = max(a[n-1].a + a[n-2].a, a[n-1].a+a[0].a+h)-min(a[1].a+a[2].a, a[0].a + a[1].a + h);
        try2 = (a[n-1].a+a[n-2].a) - (a[0].a+a[1].a);
        if (try1 < try2) {
            cout << try1 << endl;
            for (int i=0; i<n; i++) {
                if (i!=a[0].i) cout << "2 ";
                else cout << "1 ";
            }
        } else {
            cout << try2 << endl;
            for (int i=0; i<n; i++) cout << "1 ";
        }
    }
    return 0;
}