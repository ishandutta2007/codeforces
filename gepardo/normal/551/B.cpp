#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ca[256], cb[256], cc[256];
int qb, qc;
int msum, mqb, mqc;

int main()
{
    string a, b, c; cin >> a >> b >> c;
    int al = a.length(), bl = b.length(), cl = c.length();
    for (int i = 0; i < al; i++) ca[a[i]]++;
    for (int i = 0; i < bl; i++) cb[b[i]]++;
    for (int i = 0; i < cl; i++) cc[c[i]]++;
    for (;;)
    {
        bool ok = true;
        for (int i = 0; i < 256; i++)
            if (ca[i] < (cb[i] * qb)) ok = false;
        if (!ok) break;
        qc = 123456789;
        for (int i = 0; i < 256; i++)
            if (cc[i] != 0) qc = min(qc, (ca[i] - cb[i] * qb) / cc[i]);
        if (qb + qc > msum)
            msum = qb + qc,
            mqb = qb,
            mqc = qc;
        qb++;
    }
    for (int i = 0; i < mqb; i++) cout << b;
    for (int i = 0; i < mqc; i++) cout << c;
    for (int i = 0; i < 256; i++)
        for (int j = cb[i] * mqb + cc[i] * mqc; j < ca[i]; j++)
            cout << char(i);
}