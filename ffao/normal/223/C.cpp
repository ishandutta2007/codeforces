#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long mat[2000];

mat a, temp, sol, inp, id;
const int mod = 1000000007;
int n,k;

void mult(mat ret, mat a, mat b) {
    for (int i = 0; i < n; i++) ret[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ret[i] = (ret[i] + (a[j] * b[n-1 - (j-i)])) % mod;    
        }
    }
}

void copia(mat ret, mat a) {
    for (int i = 0; i < n; i++) ret[i] = a[i];
}

void exp(mat ret, mat a, int k) {
    if (k == 0) {
        copia(ret, id);
        return;
    }
    if (k == 1) {
        copia(ret, a);
        return;
    }
    exp(ret, a, k/2);
    
    mult(temp, ret, ret);
    if (k & 1) {
        mult(ret, temp, a);
    }
    else copia(ret, temp);
}

int main() {
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) a[i] = 1;
    id[n-1] = 1;
    exp(sol, a, k);
    
    for (int i = 0; i < n; i++) cin >> inp[i];
    
    long long th;
    for (int i = 0; i < n; i++) {
        th = 0;
        for (int j = 0; j <= i; j++) {
            th = (th + sol[n-1-j] * inp[i-j]) % mod;
        }
        cout << th << " ";
    }
    cout << endl;
}