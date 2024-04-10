#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long lint;

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    vector <lint> A(n), maxtill(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        maxtill[i] = A[i];
        if (i-1 >= 0)
            maxtill[i] = max(maxtill[i], maxtill[i-1]);
    }

    int m;

    scanf("%d", &m);

    lint last_upper = 0;

    for (int i = 0; i < m; i++) {
        int w, h;
        cin >> w >> h;
        
        lint ret = max(last_upper, maxtill[w-1]);
        last_upper = ret + h;

        cout << ret << endl;
    }

    return 0;
}