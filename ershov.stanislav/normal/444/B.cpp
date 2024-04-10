#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, d, cnt;
long long x;
int a[100111], b[100111], c[100111], e[100111];


long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main() {
    cin >> n >> d >> x;
    initAB();
    cnt=n;
    for (int i=0; i<n; i++) e[a[i]]=i;
    vector<int> v;
    for (int i=0; i<n; i++) if (b[i]) v.push_back(i);
    for (int i=n; i>=1&&((long long)cnt)*d>30000000; i--) {
        for (int j=e[i], k=0; k<d&&((long long)cnt)*d>30000000; k++) {
            j=e[i]+v[k];
            if (j>=n) break;
            if (i>c[j]) c[j]=i, cnt--;
        }
    }
    for (int i=0; i<n; i++) {
        if (!c[i]) {
            for (int j=0; j<d; j++) {
                if (i-v[j]<0) break;
                c[i]=max(c[i], a[i-v[j]]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}