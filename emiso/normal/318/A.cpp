#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    long long n,k,loi;
    cin >> n >> k;
    loi = (n+1)/2;
    if(k<=loi) cout << 2*k-1;
    else cout << 2*(k-loi);
    return 0;
}