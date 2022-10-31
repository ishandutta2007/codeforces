#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <cmath>

using namespace std;

int n, m;
vector<int> a, b;
vector<long long> suma, sumb;

long long getcost(int min) {
    long long i=(long long)(lower_bound(a.begin(), a.end(), min)-a.begin()), j=(long long)(b.end()-upper_bound(b.begin(), b.end(), min)), ans=0;
    if (i>0) ans+=i*min-suma[i-1];
    if (j>0) ans+=sumb[m-j]-j*min;
    return ans;
}

int main() {
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    suma.resize(n);
    sumb.resize(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long sum=0;
    for (int i=0; i<n; i++) {
        sum+=a[i];
        suma[i]=sum;
    }
    sum=0;
    for (int i=m-1; i>=0; i--) {
        sum+=b[i];
        sumb[i]=sum;
    }
    long long l=1, r=1000000000;
    while (l<r) {
        long long x=getcost((int)((2*l+r)/3)), y=getcost((int)((l+2*r+1)/3));
        if (x>=y) l=(2*l+r)/3+1;
        else r=(l+2*r+1)/3-1;
    }
    cout << getcost((int)l);
    return 0;
}