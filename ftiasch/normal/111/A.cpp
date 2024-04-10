#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long n, x, y;

int main(){
    cin >> n >> x >> y;
    long long a_1 = y - (n - 1);
    if(a_1 > 0 and a_1 * a_1 + (n - 1) >= x){
        cout << a_1 << endl;
        for(int i = 2; i <= n; ++ i){
            cout << 1 << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}