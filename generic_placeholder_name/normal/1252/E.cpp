//Hey hey it's ya boy Sseth here with another cheesy submission

#include <stdio.h>
#include <bitset>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define rep(i, n) for (int i=0; i<(n); i++)
#define sz 8192
int a[100000];
int x[100000];
bitset<100000> c;

int32_t main() {
    int n, q; scanf("%d %d", &n, &q);
    rep(i, n) scanf("%d", &a[i]);
    char ch;
    rep(i, q) {
        scanf(" %c%d", &ch, &x[i]);
        c[i]=ch=='>';
    }
    for(int i=0; i+sz<n; i+=sz) {
        rep(k, q) {
            if(c[k]) {
                for(int j=i; j<i+sz; j++) a[j]=a[j]>x[k]?-a[j]:a[j];
            }
            else {
                for(int j=i; j<i+sz; j++) a[j]=a[j]<x[k]?-a[j]:a[j];
            }
        }
    }
    rep(k, q) {
        if(c[k]) {
            for(int j=(n/sz)*sz; j<n; j++) a[j]=a[j]>x[k]?-a[j]:a[j];
        }
        else {
            for(int j=(n/sz)*sz; j<n; j++) a[j]=a[j]<x[k]?-a[j]:a[j];
        }
    }
    rep(i, n) printf("%d ", a[i]); printf("\n");
}