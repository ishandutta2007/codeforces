#include <iostream>
#include <cstdio>

using namespace std;

int getNextInt(int op) {
    cout << op << endl;
    fflush(stdout);
    int r;
    cin >> r;
    if(r == 0) exit(0);
    if(r == -2) exit(0);
    return r;
}

const int MAXN = 66;

int M, N;
bool pattern[MAXN];

int main() {
    cin >> M >> N;
    
    for(int i = 0;i < N;i++) {
        pattern[i] = getNextInt(1) == 1;
    }
    int low = 1, high = M + 1;
    int c = 0;
    while(high > low + 1) {
        int mid = low + (high-low)/2;
        if((getNextInt(mid) == 1) == pattern[c])
            low = mid;
        else 
            high = mid;
        c = (c+1)%N;
    }
    getNextInt(low);
}