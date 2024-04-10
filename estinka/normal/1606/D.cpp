#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

struct row
{
    vector<int> a;
    int i;
};
bool cmp(const row& r1, const row& r2)
{
    return r1.a[0] < r2.a[0];
}
void chmax(int& a, int b)
{
    a = max(a, b);
}
void chmin(int& a, int b)
{
    a = min(a, b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int nr, nc;
        cin >> nr >> nc;
        vector<row> a(nr);
        for (int i = 0; i < nr; i++)
        {
            a[i].a.resize(nc);
            for (int j = 0; j < nc; j++) cin >> a[i].a[j];
            a[i].i = i;
        }
        sort(a.begin(), a.end(), cmp);
        vector<vector<int> > p1(nr, vector<int>(nc));
        vector<vector<int> > p2(nr, vector<int>(nc));
        vector<vector<int> > p3(nr, vector<int>(nc));
        vector<vector<int> > p4(nr, vector<int>(nc));
        for (int i = 0; i < nr; i++) for (int j = 0; j < nc; j++) p1[i][j] = p2[i][j] = p3[i][j] = p4[i][j] = a[i].a[j];
        for (int i = 0; i < nr; i++) for (int j = nc - 1; j >= 0; j--)
        {
            if (i) chmin(p1[i][j], p1[i - 1][j]);
            if (j != nc - 1) chmin(p1[i][j], p1[i][j + 1]);
            //cout << i << ", " << j << ": " << p1[i][j] << "\n";
        } 
        //cout << "\n";
        for (int i = 0; i < nr; i++) for (int j = 0; j < nc; j++)
        {
            if (i) chmax(p2[i][j], p2[i - 1][j]);
            if (j) chmax(p2[i][j], p2[i][j - 1]);
            //cout << p2[i][j] << " \n"[j == nc - 1];
        } 
        //cout << "\n";
        for (int i = nr - 1; i >= 0; i--) for (int j = 0; j < nc; j++)
        {
            if (i != nr - 1) chmin(p3[i][j], p3[i + 1][j]);
            if (j) chmin(p3[i][j], p3[i][j - 1]);
            //cout << p3[i][j] << " \n"[j == nc - 1];
        } 
        //cout << "\n";
        for (int i = nr - 1; i >= 0; i--) for (int j = nc - 1; j >= 0; j--)
        {
            if (i != nr - 1) chmax(p4[i][j], p4[i + 1][j]);
            if (j != nc - 1) chmax(p4[i][j], p4[i][j + 1]);
            //cout << p4[i][j] << " \n"[j == nc - 1];
        } 
        //cout << "\n";
        bool yes = false;
        for (int i = 0; i < nr - 1; i++)
        {
            for (int j = 0; j < nc - 1; j++)
            {
                if (p2[i][j] < p3[i + 1][j] && p1[i][j + 1] > p4[i + 1][j + 1])
                {
                    string s(nr, 'R');
                    for (int k = 0; k <= i; k++) s[a[k].i] = 'B';
                    yes = true;
                    cout << "YES\n" << s << " " << j + 1 << "\n";
                    break;
                }
            }
            if (yes) break;
        }
        if (!yes) cout << "NO\n";
    }
    return 0;
}