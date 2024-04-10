#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;

    map<string, int> M;
    vector< pair<string, int> > A(N);
    for (int i = 0; i < N; ++i) {
        string name; int score;
        cin >> name >> score;
        M[name] += score;
        A[i] = {name, score};
    }

    int answer = 0;
    map<string, bool> winner;
    for (auto it = M.begin(); it != M.end(); ++it)
        if (it -> second > answer) {
            winner.clear();
            winner[it -> first] = true;
            answer = it -> second;
        } else
            if (it -> second == answer)
                winner[it -> first] = true;

    M.clear();
    for (int i = 0; i < N; ++i) {
        M[A[i].first] += A[i].second;
        if (winner[A[i].first] && M[A[i].first] >= answer) {
            cout << A[i].first;
            return 0;
        }
    }
}