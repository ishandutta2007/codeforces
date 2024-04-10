#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct qmark
{
    int val, place;
};

bool operator < (const qmark &a, const qmark &b)
{
    return a.val < b.val;
}

const int maxln = 5e4;
priority_queue<qmark> q;
string s;
int n, bal;
long long ans;

bool op(void)
{
    if (q.size() == 0)
        return false;
    qmark qm = q.top();
    q.pop();
    ans -= qm.val;
    s[qm.place] = '(';
    bal += 2;
    return true;
}

int main(void)
{
    cin >> s;
    n = s.length();
    int a, b;
    qmark qm;
    for (int i = 0; i < n; ++i)
    {
        switch(s[i])
        {
            case '(':
                ++bal;
                break;
            case ')':
                --bal;
                break;
            case '?':
                cin >> a >> b;
                --bal;
                ans += b;
                qm.val = b - a;
                qm.place = i;
                q.push(qm);
                s[i] = ')';
        }
        if ((bal < 0) && !op())
        {
            cout << -1 << endl;
            return 0;
        }
    }
    while (bal < 0)
        if (!op())
        {
            cout << -1 << endl;
            return 0;
        }
    if (bal > 0)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl << s << endl;
    return 0;
}