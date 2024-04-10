#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int A[200005];
int V[200005];
int N, M;
vector<int> solve(int type) {
    int K = 0, x = 1, y = N + 1;
    while (x <= N || y <= N + M) {
        while (x <= N && A[x] == type)
            V[K++] = x++;
        while (y <= N + M && A[y] == type)
            V[K++] = y++;
        type = 1 - type;
    }

    vector<int> answer;
    for (int i = 0; i < N + M; ++i)
        if (A[V[i]] != A[V[i + 1]])
            answer.push_back(i + 1);
    return answer;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    cin >> M;
    for (int i = N + 1; i <= N + M; ++i) {
        cin >> A[i];
    }
   
    vector<int> answer = solve(0);
    if (solve(1).size() < answer.size())
        answer = solve(1);
    else
        answer = solve(0);
    
    for (int i = 0; i < N + M; ++i)
        cout << V[i] << " ";
    cout << "\n";
 
    cout << answer.size() << "\n";
    for (int i = 0; i < int(answer.size()); ++i)
        cout << answer[i] << " ";
    cout << "\n";
}