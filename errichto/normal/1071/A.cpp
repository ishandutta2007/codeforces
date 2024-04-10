#include <bits/stdc++.h>
using namespace std;

void print_set(vector<int> A) {
    cout << A.size() << "\n";
    for(int x : A) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int a, b;
    cin >> a >> b;
    int s = a + b;
    int used = 0;
    int k = 1;
    while(used + k <= s) {
        used += k;
        ++k;
    }
    --k;
    cerr << "k = " << k << "\n";
    vector<int> A, B;
    for(int i = k; i >= 1; --i) {
        if(i <= a) {
            A.push_back(i);
            a -= i;
        }
        else {
            B.push_back(i);
            assert(b >= i);
            b -= i;
        }
    }
    print_set(A);
    print_set(B);
}

// 1 2 3 4  | 5 6 7

// 1+2+...+k = k*(k+1)/2 <-- total remaining space
// at least one set has space ceil(k*(k+1)/4)
// claim: ceil(k*(k+1)/4) >= k
// ceil(1*(1+1)/4) >= 1

// 4 6 10
// a=13, b=7

// knapsack