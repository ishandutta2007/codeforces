#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

int main(){
    double A, B, C, D;
    scanf("%lf%lf", &A, &B);
    scanf("%lf%lf", &C, &D);
    if (A * D > B * C){
        swap(A, B);
        swap(D, C);
    }
    double l = 0, r = 1e9;
    for (int T = 0; T < 200; ++T){
        double mid = (l + r) / 2.0;
        bool flag = false;
        double a = A - mid;
        for (int i = 0; i < 2; ++i){
            double b = B - mid;
            for (int j = 0; j < 2; ++j){
                double c = C - mid;
                for (int u = 0; u < 2; ++u){
                    double d = D - mid;
                    for (int v = 0; v < 2; ++v){
                        if (a * d > b * c){
                            flag = true;
                        }
                        d += mid; d += mid;
                    }
                    c += mid; c += mid;
                }
                b += mid; b += mid;
            }
            a += mid; a += mid;
        }
        if (flag) r = mid; else l = mid;
    }
    printf("%.12f\n", l);
    return 0;
}