#include <iostream>
#include <vector>
#include <algorithm>
#define ar(n) n[200000]

using namespace std;

struct MREC
{
    int a, e;
};

int n, ar(a), ar(e);

int ar(ps) = {}, ar(ep) = {}, ar(eu), ar(np), ar(pd), ar(no), ar(se), ar(me), u[300], mn;

bool comp(MREC a, MREC b)
{
    return a.a < b.a;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> e[i];
    for (int i = 0; i < n; i++)
    {
        ps[a[i]]++;
        ep[a[i]] += e[i];
    }
    eu[199999] = 0;
    np[199999] = 0;
    for (int i = 199998; i >= 0; i--)
    {
        eu[i] = eu[i + 1] + ep[i + 1];
        np[i] = np[i + 1] + ps[i + 1];
        no[i] = n - np[i];
        pd[i] = no[i] - ps[i] * 2 + 1;
        if (pd[i] < 0) pd[i] = 0;
    }
    vector<MREC> q(n);
    for (int i = 0; i < n; i++)
    {
        q[i].a = a[i];
        q[i].e = e[i];
    }
    sort(q.begin(), q.end(), comp);
    me[0] = 0;
    for (int i = 0; i < 300; i++) u[i] = 0;
    int it = 0;
    for (int i = 1; i < 200000; i++)
    {
        me[i] = 0;
        while ((q[it].a < i) && (it < n))
        {
            u[q[it].e]++;
            it++;
        }
        int taken = 0;
        //cout << "i = " << i << endl;
        for (int j = 0; j < 300; j++)
        {
            me[i] += (j * u[j]);
            taken += u[j];
            //cout << "j = " << j << " pd = " << pd[i] << " me = " << me[i] << " taken = " << taken << endl;
            if (taken > pd[i])
            {
                me[i] -= (j * (taken - pd[i]));
                break;
            }
        }
    }

    /*for (int i = 0; i < 9; i++) cout << ps[i] << " "; cout << endl;
    for (int i = 0; i < 9; i++) cout << np[i] << " "; cout << endl;
    for (int i = 0; i < 9; i++) cout << no[i] << " "; cout << endl;
    for (int i = 0; i < 9; i++) cout << pd[i] << " "; cout << endl;
    cout << endl;
    for (int i = 0; i < 9; i++) cout << ep[i] << " "; cout << endl;
    for (int i = 0; i < 9; i++) cout << eu[i] << " "; cout << endl;
    for (int i = 0; i < 9; i++) cout << me[i] << " "; cout << endl;*/

    mn = eu[q[0].a] + me[q[0].a];
    for (int i = q[0].a + 1; i < 200000; i++)
        if (((eu[i] + me[i]) < mn) && (ps[i] != 0))
            {
                mn = eu[i] + me[i];
                //cout << i << endl;
            }
    cout << mn;
}