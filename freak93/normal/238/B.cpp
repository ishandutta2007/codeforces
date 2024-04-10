#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1000000000;

class compare {
  public:
    compare(const vector<int> &_V) : V(_V) {}
    bool operator()(const int &x, const int &y) const {
        return V[x] < V[y];
    }
  private:
    const vector<int> &V;
};

int main() {
    int N, H; cin >> N >> H;

    vector<int> V(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];

    if (N <= 2) {
        int answer = 0;
        int cost = inf;

        for (int i = 0; i < (1 << N); ++i)  {
            vector<int> A, B;
            for (int j = 0; j < N; ++j)
                if ((1 << j) & i)
                    A.push_back(V[j]);
                else
                    B.push_back(V[j]);

            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            int maxt = -1, mint = inf;
            if (int(A.size()) > 1) {
                maxt = max(maxt, A[A.size() - 1] + A[A.size() - 2]);
                mint = min(mint, A[0] + A[1]);
            }

            if (int(B.size()) > 1) {
                maxt = max(maxt, B[B.size() - 1] + B[B.size() - 2]);
                mint = min(mint, B[0] + B[1]);
            }

            if (A.size() && B.size()) {
                maxt = max(maxt, A.back() + B.back() + H);
                mint = min(mint, A[0] + B[0] + H);
            }

            if (maxt - mint < cost) {
                cost = maxt - mint;
                answer = i;
            }
        }

        cout << cost << "\n";
        for (int i = 0; i < N; ++i)
            if ((1 << i) & answer)
                cout << "1 ";
            else
                cout << "2 ";
        return 0;
    }

    // all in 1 team
    int case1 = inf;
    { 
        vector<int> A = V;
        sort(A.begin(), A.end());
        int mint = A[0] + A[1];
        int maxt = A[A.size() - 1] + A[A.size() - 2];
        case1 = maxt - mint;
    }

    int case2 = inf;
    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        P[i] = i;
    sort(P.begin(), P.end(), compare(V));
    vector<int> A = V;
    sort(A.begin(), A.end());

    case2 = max(A[N - 1] + A[N - 2], A[0] + A[N - 1] + H) - min(A[0] + A[1] + H, A[1] + A[2]);
    if (case1 < case2) {
        cout << case1<< "\n";
        for (int i = 0; i < N; ++i)
            cout << 2<< " ";
        return 0;
    }

    cout << case2 << "\n";
    for (int i = 0; i < N; ++i)
        if (i == P[0])
            cout << 1 << " ";
        else
            cout << 2 << " ";
}