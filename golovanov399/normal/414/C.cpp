#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 

#define itn int 
#define float long double 
#define LL long long 
#define pb push_back 
#define mp make_pair 

using namespace std; 

int main(){ 
    
    int n;
    scanf("%d", &n);
    int k = 1 << n;
    vector<int> a(k);
    for (int i = 0; i < k; i++){
        scanf("%d", &a[i]);
    }
    vector<LL> d(n + 1);
    d[0] = 0;
    int m = 1;
    LL s = 0;
    for (int i = 0; i < n; i++){
        vector<int> p(m), q(m);
        d[i + 1] = 0;
        LL w = 0;
        for (int j = 0; j < k; j += m + m){
            for (int ij = 0; ij < m; ij++) p[ij] = a[j + ij];
            for (int ij = 0; ij < m; ij++) q[ij] = a[j + m + ij];
            int i1 = 0, j1 = 0;
            while (i1 + j1 < m + m){
                if (i1 == m){
                    a[j + i1 + j1] = q[j1];
                    j1++;
                } else
                if (j1 == m){
                    a[j + i1 + j1] = p[i1];
                    i1++;
                    d[i + 1] += j1;
                } else {
                    if (p[i1] <= q[j1]){
                        a[j + i1 + j1] = p[i1];
                        i1++;
                        d[i + 1] += j1;
                    } else {
                        a[j + i1 + j1] = q[j1];
                        j1++;
                    }
                }
            }
            LL c1 = 1, c2 = 1;
            i1 = j1 = 0;
            while (i1 < m && j1 < m){
                if (p[i1] < q[j1]) i1++; else
                if (p[i1] > q[j1]) j1++; else
                {
                    i1++;
                    j1++;
                    while (i1 < m && p[i1] == p[i1 - 1]){
                        i1++; c1++;
                    }
                    while (j1 < m && q[j1] == q[j1 - 1]){
                        j1++; c2++;
                    }
                    w += c1 * c2;
                    c1 = c2 = 1;
                }
            }
        }
        m *= 2;
        s += d[i + 1];
        d[i + 1] = (LL)k * m / 4 - w - d[i + 1] - d[i + 1];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        int x;
        scanf("%d", &x);
        for (int j = 0; j <= x; j++){
            s += d[j];
            d[j] = -d[j];
        }
        printf("%I64d\n", s);
    }
    
    return 0; 
}