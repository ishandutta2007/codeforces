#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kModulo = 1000000007;

int pow(int x, int y) {
    if (y == 0)
        return 1;
    if (y % 2)
        return (1LL * x * pow(x, y - 1)) % kModulo;
    int val = pow(x, y / 2);
    return (1LL * val * val) % kModulo;
}

int solve(vector<int> V) {
    int N = V.size();

    vector<int> fact(N + 1), ifact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = (1LL * i * fact[i - 1]) % kModulo;
    ifact[N] = pow(fact[N], kModulo - 2);
    for (int i = N - 1; i >= 0; --i)
        ifact[i] = (1LL * ifact[i + 1] * (i + 1)) % kModulo;

    int start = 0;
    for (int i = 0; i < N; ++i)
        if (V[i] == 1) {
            start = i;
            break;
        }

    int X = start, Y = start;

    vector< pair<int, int> > steps;
    for (int i = 0; i < N; ++i)
        if (V[i] != 0 and V[i] != 1)
            steps.push_back({V[i], i});
    sort(steps.begin(), steps.end());
    int answer = 1;
    for (auto &next : steps) {
        int length = next.first;
        int now = next.second;
        if (now >= X and now <= Y)
            return 0;

        int total = 0;
        int left = 0;
        while (X != now && Y != now) {
            if (now < X) {
                --X;
                ++left;
            } else
                if (now > Y)
                    ++Y;
                else
                    return 0;
            ++total;
        }

        while (Y - X + 1 != length) {
            if (X == now) {
                ++Y;
                if (Y == N)
                    return 0;
            } else {
                --X;
                ++left;
                if (X < 0)
                    return 0;
            }
            ++total;
        }

        --total;
        if (X == now)
            --left;
        answer = (1LL * answer * fact[total]) % kModulo;
        answer = (1LL * answer * ifact[left]) % kModulo;
        answer = (1LL * answer * ifact[total - left]) % kModulo;
    }

    int A = N - (Y - X + 1);
    int B = X;

    // the answer is combinations of A taken B
    answer = (1LL * answer * fact[A]) % kModulo;
    answer = (1LL * answer * ifact[B]) % kModulo;
    answer = (1LL * answer * ifact[A - B]) % kModulo;
    return answer;
}

int main() {
    int N; cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];

    if (*max_element(V.begin(), V.end()) == 0) {
        cout << pow(2, N - 1) << "\n";
        return 0;
    }

    int mint = N + 1, where = -1;
    for (int i = 0; i < N; ++i)
        if (V[i] > 0 and V[i] < mint) {
            mint = V[i];
            where = i;
        }

    int answer = 0;
    if (mint == 1)
        answer += solve(V);
    else {
        --mint;
        int multiplier = pow(2, mint - 1);

        if (where >= mint)
            if (V[where - mint] == 0) {
                V[where - mint] = 1;
                answer += solve(V);
                V[where - mint] = 0;
            }
        if (where + mint < N)
            if (V[where + mint] == 0) {
                V[where + mint] = 1;
                answer += solve(V);
                V[where + mint] = 0;
            }
        answer = (1LL * answer * multiplier) % kModulo;
    }

    cout << answer % kModulo << "\n";
}