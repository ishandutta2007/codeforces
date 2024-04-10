#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <vector <string>> field(9, vector <string> (3));
    for (int i = 0; i < 9; ++i) {
        string s;
        cin >> s;
        field[i % 3][i / 3] = s;
    }
    for (int i = 0; i < 9; ++i) {
        string s;
        cin >> s;
        field[i % 3 + 3][i / 3] = s;
    }
    for (int i = 0; i < 9; ++i) {
        string s;
        cin >> s;
        field[i % 3 + 6][i / 3] = s;
    }
    int x, y;
    cin >> x >> y;
    --x, --y;
    x %= 3;
    y %= 3;
    int z = x * 3 + y;
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (field[z][i][j] == '.') flag = false;
        }
    }
    if (flag) {
        for (auto &v : field) {
            for (auto &s : v) {
                for (auto &c : s) {
                    if (c == '.') c = '!';
                }
            }
        }
    }
    else {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (field[z][i][j] == '.') field[z][i][j] = '!';
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << field[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 6; ++j) {
            cout << field[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 6; j < 9; ++j) {
            cout << field[j][i] << " ";
        }
        cout << endl;
    }
}