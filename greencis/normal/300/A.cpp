#include <iostream>
#include <vector>
using namespace std;

int n,a[105],pos,posi,posn,neg,negi,negn;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0) {
            ++pos;
            posi = i;
            posn = a[i];
        }
        if (a[i] < 0) {
            ++neg;
            negi = i;
            negn = a[i];
        }

    }

    if (neg == 1) {
        cout << "1 " << negn << endl;
        cout << "1 " << posn << endl;
        cout << n-2 << " ";
        for (int i = 0; i < n; ++i)
            if (i != posi && i != negi)
                cout << a[i] << " ";
    } else {
        if (pos >= 1) {
            cout << "1 " << negn << endl;
            cout << "1 " << posn << endl;
            cout << n-2 << " ";
            for (int i = 0; i < n; ++i)
                if (i != posi && i != negi)
                    cout << a[i] << " ";
        } else {
            int cnt = 0;
            vector<int> ans;
            cout << "1 ";
            int i = 0;
            for (; i < n; ++i) {
                if (a[i] < 0) {
                    cout << a[i] << endl;
                    ++cnt; ++i;
                    break;
                } else ans.push_back(a[i]);
            }
            cout << "2 ";
            for (; i < n; ++i) {
                if (a[i] < 0 && cnt < 3) {
                    cout << a[i] << " ";
                    ++cnt;
                } else ans.push_back(a[i]);
            }
            cout << endl<<n-3 << " ";
            for (i = 0; i < ans.size(); ++i)
                cout << ans[i] << " ";
        }
    }

    return 0;
}