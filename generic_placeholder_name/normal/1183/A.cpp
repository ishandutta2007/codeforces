#include <bits/stdc++.h>

using namespace std;
int main() {
    int a, b;
    cin >> a;
    b=-1;
    while ((b%4)!=0) {
        int tmp=a; b=0;
        while (a!=0) {
            b+=(a%10);
            a/=10;
        }
        a=tmp+1;
    }
    cout << a-1;
}