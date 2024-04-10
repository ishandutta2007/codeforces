#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int kInf = 1000 * 1000 * 1000;

struct TRMQ {
    int logleaves;
    int size;
    int shift;

    vector <int> body;

    TRMQ(int n) {
        logleaves = 1;
        while ((1 << logleaves) < n) {
            logleaves++;
        }
        size = (1 << (logleaves + 1));
        shift = size / 2;
        body.resize(size, -kInf);
    }

    void Change(int pos, int value) {
        int tpos = pos + shift;
        body[tpos] = value;
        while (tpos > 1) {
            tpos /= 2;
            body[tpos] = max(body[tpos * 2], body[tpos * 2 + 1]);
        }
    }

    int MaxQueryRec(int node, int i, int j, int lb, int rb) {
//        cerr << "maxqueryrec: " << node << ' ' << i << ' ' << j << ' ' << lb << ' ' << rb << endl;
        if (i > rb || j < lb) {
            return -kInf;
        }
        if (lb >= i && rb <= j) {
            return body[node];
        }
        return max(MaxQueryRec(node * 2, i, j, lb, (lb + rb) / 2), MaxQueryRec(node * 2 + 1, i, j, (lb + rb) / 2 + 1, rb));
    }

    int MaxQuery(int i, int j) {
        if (j < i) {
            return -kInf;
        }        
        return MaxQueryRec(1, i + 1, j + 1, 1, shift);
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tc;

    scanf("%d", &tc);

    for (int test = 0; test < tc; test++) {
        int n;
        scanf("%d", &n);

        vector <long long> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }    

        vector <pair <long long, int> > psum;
        long long sum = 0ll;
        for (int i = 0; i <= n; i++) {
            psum.pb(mp(sum, i));
            if (i < n) {
                sum += a[i];
            }
        }

        sort(psum.begin(), psum.end());

        TRMQ rmqPositive(n + 1);
        TRMQ rmqZero(n + 1);
        TRMQ rmqNegative(n + 1);
        
        sum = 0ll;
        int lastans = 0;
        for (int i = 0; i <= n; i++) {
  //          cerr << "body negative: ";
    //        for (int i = 0; i < rmqNegative.size; i++) {
      //          cerr << rmqNegative.body[i] << ' ';
        //    }
          //  cerr << endl;
            if (i > 0) {
                sum += a[i - 1];

                int sumstart = lower_bound(psum.begin(), psum.end(), mp(sum, -1)) - psum.begin();
                int sumfinish = lower_bound(psum.begin(), psum.end(), mp(sum, n + 2)) - psum.begin();
            //    cerr << "sums: " << sumstart << ' ' << sumfinish << endl;
                int posans = rmqPositive.MaxQuery(0, sumstart - 1) + i;
                int zeroans = rmqZero.MaxQuery(sumstart, sumfinish - 1);
                int negans = rmqNegative.MaxQuery(sumfinish, n) - i;
            //    cerr << i << ' ' << posans << ' ' << zeroans << ' ' << negans << endl;
                lastans = max(posans, max(zeroans, negans));
            }
            int curpos = lower_bound(psum.begin(), psum.end(), mp(sum, i)) - psum.begin();
            rmqPositive.Change(curpos, lastans - i);
            rmqNegative.Change(curpos, lastans + i);
            rmqZero.Change(curpos, lastans);
            //cerr << i << ' ' << lastans << ' ' << curpos << endl;
        }

        printf("%d\n", lastans);
    }

    return 0;
}