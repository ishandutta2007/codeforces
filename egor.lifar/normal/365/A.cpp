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

string a[1000];

int main() {
    int n, k;
    cin >> n >> k;
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        bool b[1000];
        for(int j = 0; j <= k; j++){
            b[j] = false;
        }
        for(int j = 0; j < (int)a[i].size(); j++){
            b[a[i][j] - '0'] = true;
        }
        bool m = true;
        for(int j = 0; j <= k; j++){
            if(!b[j]){
                m = false;
            }
        }
        if(m){
            s++;
        }
    }
    cout << s << endl;
    return 0;
}