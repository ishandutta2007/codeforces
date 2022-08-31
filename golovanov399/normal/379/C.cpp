#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>

#define float long double
#define LL long long
#define itn int

using namespace std;

int main(){

//  freopen("courier.in", "r", stdin);
//  freopen("courier.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) a[i].second = i;
    vector<int> b(n);
    sort(a.begin(), a.end());
    int k = -1;
    for (int i = 0; i < n; i++){
        if (a[i].first > k) k = a[i].first; else k++;
        b[a[i].second] = k;
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    
    return 0;

}