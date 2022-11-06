#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

#define MAXN 100010

using namespace std;

typedef long long lint;

lint val[MAXN], val2[MAXN], val3[MAXN];

int main()
{
    lint n, k, sum = 0;
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> val[i];
        sum += val[i];
        val3[i] = val2[i] = val[i];
    }

    if (k > sum) {
        cout << "-1" << endl;
        return 0;
    }
    if (sum == k) {
        cout << "" << endl;
        return 0;
    }

    sort(val2, val2+n);
    sort(val3, val3+n);

    int nn = unique(val3, val3+n)-val3;
    lint nguy = n;

    int j = 0; 
    for (lint round = 0;;) {
        if (j < nn && round == val3[j]) {
            nguy = (val2+n)-upper_bound(val2, val2+n, round);
            j++;
        }

        if (k >= nguy) {
            lint maxdelta = k/nguy;
            if (j < nn)
                maxdelta = min(maxdelta, val3[j]-round);
            round += maxdelta;
            k -= maxdelta * nguy;
        } else {
            vector <int> ret;
            int start = -1;

            for (int i = 0; i < n; i++)
                if (val[i] > round) {
                    k --;
                    if (k < 0 || val[i] > round+1) {
                        ret.push_back(i);
                        if (k < 0 && start == -1)
                            start = (int)ret.size()-1;
                    }
                }
            if (start == -1)
                start = 0;
            rotate(ret.begin(), ret.begin()+start, ret.end());
            
            for (int i = 0; i < (int)ret.size(); i++) {
                cout << ret[i] + 1;
                if (i+1 < (int)ret.size())
                    cout << " ";
            }
            cout << endl;
            break;
        }
    }
    
    return 0;
}