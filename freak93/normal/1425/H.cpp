#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int A, B, C, D; cin >> A >> B >> C >> D;

        int answer[4] = {0, 0, 0, 0};
        if (A || D)
            answer[0] = answer[3] = 1;
        if (B || C)
            answer[1] = answer[2] = 1;
        if ((A + B) % 2)
            answer[2] = answer[3] = 0;
        else 
            answer[0] = answer[1] = 0;

        for (int i = 0; i < 4; ++i)
            if (answer[i])
                cout << "Ya ";
            else 
                cout << "Tidak ";
        cout << "\n";
    }
}