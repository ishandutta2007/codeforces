#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define double long double
using namespace std;

const double e = 1e-12;
double pi = asin(1) * 2;
vector <pair <double, int> > sobs;

//overtroll's solution, modified a bit

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    double d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        double x, y, r;
        cin >> x >> y >> r;
        double dd = sqrtf(x * x + y * y);
        double mnr = dd - r, mxr = dd + r;
        int id = (int)((mnr - e) / d);
        while (d * id + e < mnr) id++;
        double mang = -e;
        while (d * (double)id < mxr + e)
        {
            double aa = r, bb = d * (double)id, cc = dd;
            mang =  acos((bb * bb + cc * cc - aa * aa) / 2.0 / bb / cc - e);
            double ml = atan2(y, x);
            double mr = ml + mang;
            ml -= mang;
            if (ml < -pi) ml += 2 * pi;
            if (mr > pi) mr -= 2 * pi;
            sobs.push_back(make_pair(ml, 1));
            sobs.push_back(make_pair(mr, -1));
            if (ml > mr)
            {
                sobs.push_back(make_pair(-pi, 1));
                sobs.push_back(make_pair(pi, -1));
            }
            id++;
        }
    }
    sort(sobs.begin(), sobs.end());
    int cn = 0, rs = 0, minu = 0;
    for (int i = 0; i < (int)sobs.size(); i++)
    {
        if (sobs[i].second == -1)
            ++minu;
        else {
            ++cn;
            if (!i || abs(sobs[i].first - sobs[i - 1].first) > 1e-9) {
                cn -= minu;
                minu = 0;
            }
        }
        rs = max(rs, cn);
    }
    cout << rs << endl;
    return 0;
}