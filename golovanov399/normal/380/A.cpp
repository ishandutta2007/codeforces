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

using namespace std; 

int main(){ 
    
    int m;
    cin >> m;
    vector<LL> d(m);
    vector<int> tp(m);
    vector<pair<int, int> > qw(m);
    for (int i = 0; i < m; i++){
        cin >> tp[i];
        if (tp[i] == 1){
            cin >> qw[i].first;
            if (i == 0) d[i] = 1; else
            d[i] = d[i - 1] + 1;
        } else {
            cin >> qw[i].first >> qw[i].second;
            d[i] = d[i - 1] + qw[i].first * qw[i].second;
        }
    }
    int n;
    cin >> n;
    int l, r, mid;
    for (int i = 0; i < n; i++){
        LL ind;
        cin >> ind;
        l = 0, r = m;
        while (r > l + 1){
            mid = (l + r) / 2;
            if (d[mid] < ind) l = mid; else r = mid;
        }
        l++;
        while (ind != d[l] || tp[l] != 1){
//          cout << "Now ind is equal to " << ind << ", and l is equal to " << l << "\n";
            if (tp[l] == 1) l--; else
            if (d[l - 1] >= ind) l--; else {
                ind = (ind - d[l - 1]) % qw[l].first;
                if (ind == 0) ind = qw[l].first;
                l = distance(d.begin(), lower_bound(d.begin(), d.end(), ind));
            }
        }
        cout << qw[l].first << " ";
    }
    
    return 0; 
}