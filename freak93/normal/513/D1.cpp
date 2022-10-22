#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 1000 * 1000 + 5;

vector<int> L[kMaxN], R[kMaxN], A[kMaxN];

int val = 2;

void clean(vector<int> &V) {
    while (V.size() && V.back() < val)
        V.pop_back();
}

void mergeInto(vector<int> &A, vector<int> &B) {
    if (A.size() <= B.size()) {
        B.insert(B.end(), A.begin(), A.end());
        A.clear();
    } else {
        A.insert(A.end(), B.begin(), B.end());
        B.clear();
        A.swap(B);
    }
}

int Left[kMaxN], Right[kMaxN];

void dfs(int node) {
    clean(L[node]);
    if (L[node].size()) {
        Left[node] = val;
        mergeInto(L[node], A[val]);
        dfs(val++);
    }
    clean(R[node]);
    clean(A[node]);
    if (R[node].size()) {
        Right[node] = val;
        mergeInto(R[node], A[val]);
        mergeInto(A[node], A[val]);
        dfs(val++);
    }

    if (!Right[node] && A[node].size()) {
        Right[node] = val;
        mergeInto(R[node], A[val]);
        mergeInto(A[node], A[val]);
        dfs(val++);
    }
}

vector<int> answer;
int tt;
int Enter[kMaxN], Exit[kMaxN], Middle[kMaxN];
void inorder(int node) {
    Enter[node] = ++tt;
    if (Left[node])
        inorder(Left[node]);
    answer.push_back(node);
    Middle[node] = ++tt;
    if (Right[node])
        inorder(Right[node]);
    Exit[node] = ++tt;
}

int main() {
    ios::sync_with_stdio(false);
    int N, C; cin >> N >> C;

    vector<int> A(C), B(C);
    vector<string> S(C);

    for (int i = 0; i < C; ++i) {
        cin >> A[i] >> B[i] >> S[i];
        if (A[i] == B[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (S[i] == "LEFT")
            L[A[i]].push_back(B[i]);
        else
            R[A[i]].push_back(B[i]);
    }

    for (int i = 1; i <= N; ++i)
        ::A[1].push_back(i);

    dfs(1);

    inorder(1);
    if (int(answer.size()) < N) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    bool bad = false;
    for (int i = 0; i < C; ++i) {
        if (!(Enter[B[i]] > Enter[A[i]] && Exit[B[i]] < Exit[A[i]])) {
            bad = true;
            break;
        }

        if (S[i] == "LEFT")
            if (Exit[B[i]] > Middle[A[i]]) {
                bad = true;
                break;
            }
        if (S[i] == "RIGHT")
            if (Exit[B[i]] < Middle[A[i]]) {
                bad = true;
                break;
            }
    }

    if (bad) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto &x : answer)
        cout << x << " ";
    cout << "\n";
}