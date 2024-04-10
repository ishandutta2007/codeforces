#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = 0, nowM = -1, nowH = -1, now_res = 0;
    for (int i=0; i<n; i++) {
        int h, m;
        cin >> h >> m;
        if (h == nowH && m == nowM) now_res++;
        else {
            if (now_res > max) max = now_res;
            nowH = h;
            nowM = m;
            now_res = 1;
        }
    }
    if (now_res > max) max = now_res;
    cout << max;
    return 0;
}