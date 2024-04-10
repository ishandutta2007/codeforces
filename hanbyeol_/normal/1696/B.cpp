#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        deque<int> A;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        while (!A.empty() && A.front() == 0)
            A.pop_front();
        while (!A.empty() && A.back() == 0)
            A.pop_back();
        if (A.empty())
            cout << 0 << endl;
        else if (*min_element(A.begin(), A.end()) == 0)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
}