#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>



using namespace std;

vector<int> v;
int a[100000];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 1 && a[i] == a[i - 2] + a[i - 1]){
            v.push_back(i);
        }
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    int l = 2;
    int r = 0;
    int m = 0;
    for(int i = 0; i <= (int)v.size(); i++){
        if(i < v.size() && (i == 0 || (i > 0 && v[i] == v[i - 1] + 1))){
            m++;
        }else{
            r = max(r, m);
            m = 1;
        }
    }
    cout << l + r << endl;
    return 0;
}