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


int main(){
    int r = 0, p = 0, s = 0;
    int n;
    cin >> n;
    int a[4], b[4], c[4], d[4];
    for(int i = 0; i < 4; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        int k, l;
        k = min(a[i], b[i]);
        l = min(c[i], d[i]);
        if(k + l <= n){
            r = i + 1;
            if(k > l){
                p = max(k, l);
                s = n - max(k, l);
            }else{
                p = n - max(k, l);
                s = max(k, l);
            }

        }
    }
    if(r == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << r << ' ' << p << ' ' << s << endl;
    return 0;
}