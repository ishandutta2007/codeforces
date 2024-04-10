#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s;
vector<int> pre, nxt, live;

void prints(int p)
{
    if (p < 0) return;
    prints(pre[p]);
    cout << s[p];
}

void rem(int p)
{
    pre[nxt[p]] = pre[p];
    nxt[pre[p]] = nxt[p];
    live[p] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int p = 1;
    getline(cin, s);
    pre.resize(s.length());
    nxt.resize(s.length());
    live.resize(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        pre[i] = i - 1;
        nxt[i] = i + 1;
        live[i] = 1;
    }
    nxt[s.length() - 1] = -1;
    int l = s.length();
    while ((p > 0) && (l > 1))
    {
        /*
        int q = s.length() - 1;
        while (live[q] == 0) { q--; if (q < 0) return 0; }
        prints(q);
        cout << " " << p << " " << endl;
        for (int i = 0; i < s.length(); i++) cout << pre[i] << " "; cout << endl;
        for (int i = 0; i < s.length(); i++) cout << nxt[i] << " "; cout << endl;
        for (int i = 0; i < s.length(); i++) cout << live[i] << " "; cout << endl;
        */
        if (s[p] == s[pre[p]])
        {
            int np = nxt[p];
            rem(p); rem(pre[p]);
            l -= 2;
            p = np;
        }
        else p = nxt[p];
    }
    int q = s.length() - 1;
    while (live[q] == 0) { q--; if (q < 0) return 0; }
    prints(q);
    return 0;
}