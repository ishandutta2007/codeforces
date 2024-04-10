#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int Query(vector<int> x, vector<int> y)
{
    int i;
    string o;

    cout << "? " << x.size() << ' ' << y.size() << endl;
    for(i = 0; i < (signed)x.size(); i ++)
        cout << x[i] << " \n"[i == (signed)x.size() - 1];
    for(i = 0; i < (signed)y.size(); i ++)
        cout << y[i] << " \n"[i == (signed)y.size() - 1];
    
    cout.flush();
    cin >> o;

    return o == "SECOND" ? -1 : o == "FIRST";
}

void Answer(int x)
{
    cout << "! " << x << endl;
    cout.flush();

    return;
}

int Solve(vector<int> x, vector<int> y)
{
    int l, m, r;

    for(l = -1, r = (int)y.size() - 1; l + 1 < r; )
    {
        m = (l + r) / 2;
        if(!Query(vector<int>(x.begin(), x.begin() + m + 1), vector<int>(y.begin(), y.begin() + m + 1)))
            l = m;
        else
            r = m;
    }

    return y[r];
}

int main(void)
{
    int t, n, k;
    int i, p, q;
    vector<int> x, y;

    cin >> t;
    while(t --)
    {
        cin >> n >> k;
        for(i = 0, p = 1; i < 30; i ++)
        {
            do
                q = rand() % n + 1;
            while(p == q);
            if(Query({p}, {q}) == -1)
                p = q;
        }

        x = {p};
        y.clear();
        for(i = 1; i <= n; i ++)
            if(i != p)
                y.push_back(i);

        while(true)
        {
            q = (int)min(x.size(), y.size());
            if(!Query(vector<int>(x.begin(), x.begin() + q), vector<int>(y.begin(), y.begin() + q)))
            {
                x.insert(x.end(), y.begin(), y.begin() + q);
                y.erase(y.begin(), y.begin() + q);
            }
            else
            {
                Answer(Solve(vector<int>(x.begin(), x.begin() + q), vector<int>(y.begin(), y.begin() + q)));
                break;
            }
        }
    }

    return 0;
}