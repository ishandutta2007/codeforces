#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   
    int n, k, l, c, d, p, nl, np, m, nc;
    scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
    m = 1;
    nc = d * c;
    while(m * n * nl <= k * l && m * n * np <= p && m * n <= nc){
        m++;
    }
    printf("%d\n", m-1);
    // int n;
    // scanf("%d", &n);
    // vector <pair < int, int > > p(n);    
    // for(int i = 0; i < n; i++){
    //     scanf("%d %d", &p[i].second, &p[i].first);
    // }
    // sort(p.begin(), p.end());

    // int k = 1;
    // int s = 0;
    // for(int i = n - 1; i >= 0 && k > 0; i--){
    //    s += p[i].second;
    //    k--;
    //    k += p[i].first; 
    // }
    // printf("%d\n", s);
    return 0;
}