#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin() (x).end()

using namespace std;

int main(){

    int n;
    cin >> n;
    int s = 0;
    int cur = 0;
    int i = 0;
    while (s <= n){
        i++;
        cur += i;
        s += cur; 
    }
    cout << i - 1 << "\n";

    return 0;
}