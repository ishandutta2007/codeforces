#include <iostream>
#include <cstdio>

#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAXN = 1000;
const ld EPS = 0.000000001;


int N, M;
int a[MAXN], b[MAXN];

ld gv(ld l, int e) {
    if(e <= 1) return -1.0;
    return (l + l/(e - 1));
}

int main() {
    
    //freopen("fly.in", "r", stdin);
    
    cin >> N >> M;
    
    for(int i = 0;i < N;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < N;i++) {
        cin >> b[i];
    }
    
    ld fin = (ld) M;
    for(int i = N-1;i >= 0;i--) {
        if(i < N-1) fin = gv(fin, a[i]);
        if(fin < 0) goto failed;
        if(i > 0) fin = gv(fin, b[i]);
        if(fin < 0) goto failed;
    }
    
    fin = gv(fin, a[N-1]);
    if(fin < 0) goto failed;
    fin = gv(fin, b[0]);
    if(fin < 0) goto failed;
    fin -= (ld) M;
    if(fin < 0) goto failed;
    
    cout << setprecision(8) << fin << endl;
    return 0;
    
    failed:
    cout << -1 << endl;
    
    return 0;
}