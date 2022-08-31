#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector< int > A(N);
        for(auto& a : A) cin >> a;

        for(int i = 0; i < N; i++) {
            if(i > 0) cout << " ";

            int X;
            cin >> X;
            string F;
            cin >> F;
            int up = count(F.begin(), F.end(), 'D');
            int down = (int) F.size() - up;
            A[i] += up;
            A[i] += 10 - down % 10;
            A[i] %= 10;
            cout << A[i];
        }
        cout << endl;
    }
}