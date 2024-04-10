#include <bits/stdc++.h>
using namespace std;

int t;
vector <string> imena;
vector <vector <string> > mog;
vector <string> vs;
vector <string> rj;
vector <string> zad;
string s;
bool z;

int main()
{
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++)
    {
        imena.clear();
        mog.clear();
        rj.clear();
        zad.clear();
        z = 1;
        int n, m;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            imena.push_back(s);
        }
        scanf("%d\n", &m);
        mog.insert(mog.begin(), m, vs);
        for (int i = 0; i < m; i++)
        {
            getline(cin, s);
            zad.push_back("");
            int br = 0;
            while (s [br] != ':') br++;
            br++;
            for (int j = br; j < s.size(); j++) zad [i] += s [j];
            if (s [0] != '?')
            {
                int br = 0;
                string tr = "";
                while (s [br] != ':')
                {
                    tr += s [br]; br++;
                }
                mog [i].push_back(tr);
            }
            else
            {
                mog [i] = imena;
                int br = 2;
                string tr = "";
                s += '.';
                for (int j = br; j < s.size(); j++)
                {
                    if ((s [j] < 'a' || s [j] > 'z') && (s [j] < 'A' || s [j] > 'Z') && (s [j] < '0' || s [j] > '9'))
                    {
                        for (int k = 0; k < mog [i].size(); k++) if (mog [i] [k] == tr) {mog [i].erase(mog [i].begin() + k, mog [i].begin() + k + 1); tr = ""; break;}
                        tr = "";
                    }
                    else tr += s [j];
                }
                s.erase(s.begin() + s.size() - 1, s.begin() + s.size());
                if (i != 0 && mog [i - 1].size() == 1)
                {
                    for (int k = 0; k < mog [i].size(); k++) if (mog [i] [k] == mog [i - 1] [0]) {mog [i].erase(mog [i].begin() + k, mog [i].begin() + k + 1); break;}
                }
                if (!mog [i].size()) z = 0;
            }
        }
        if (z)
        for (int i = m - 1; i >= 0; i--)
        {
            rj.push_back(mog [i] [0]);
            if (i != 0)
            {
                for (int j = 0; j < mog [i - 1].size(); j++)
                {
                    if (mog [i] [0] == mog [i - 1] [j]) {mog [i - 1].erase(mog [i - 1].begin() + j, mog [i - 1].begin() + j + 1); break;}
                }
            }
            if (!mog [i - 1].size()) {z = 0; break;}
        }
        if (!z) {printf("Impossible\n"); continue;}
        reverse(rj.begin(), rj.end());
        for (int i = 0; i < rj.size(); i++)
        {
            cout << rj [i] << ":" << zad [i] << endl;
        }
    }
    return 0;
}