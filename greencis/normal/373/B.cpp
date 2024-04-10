#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
using namespace std;

char p[25];

long long cnt(long long a) {
    if (a == 0) return 1;
    long long q = 0;
    while (a) {
        ++q;
        a /= 10;
    }
    return q;
}

long long power(long long a, long long b) {
    if (b == 1) return a;
    return a * pow(a, b-1);
}

int main()
{
    long long w,m,k,res=0;
    cin >> w >> m >> k;
    w/=k;
    k=1;
    long long m_a = m;
    long long m_cnt = cnt(m);
    long long m_next_10 = power(10,m_cnt);
    if (m_next_10 - m >= w) {
        //cout << "A";
        cout << w / m_cnt;
        return 0;
    } else {
        if (w - (m_next_10 - m) * m_cnt <= 0) {
            cout << w/m_cnt;
            return 0;
        } else {
            res += m_next_10 - m;
            w -= (m_next_10 - m) * m_cnt;
        }
        m = m_next_10;
        m_next_10 *= 10;
        m_cnt++;
        while (1) {
            if (m_next_10 - m >= w) {
                cout << res + w/m_cnt<<endl;
                return 0;
            } else {
                if (w - (m_next_10 - m) * m_cnt <= 0) {
                    cout << res + w / m_cnt;
                    return 0;
                } else {
                    res += m_next_10 - m;
                    w -= (m_next_10 - m) * m_cnt;
                }
                m = m_next_10;
                m_next_10 *= 10;
                m_cnt++;
            }
        }
    }

    return 0;
}