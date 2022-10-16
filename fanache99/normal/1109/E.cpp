#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];

    inline void advance() {
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 100000;
int mod, phi;
vector<int> primes;

vector<int> getPrimes(int x) {
    vector<int> ans;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            ans.push_back(d);
            while (x % d == 0) {
                x /= d;
            }
        }
    }
    if (x != 1) {
        ans.push_back(x);
    }
    phi = mod;
    for (auto it : ans) {
        phi = (phi / it) * (it - 1);
    }
    return ans;
}

int v[1 + MAXN];

struct Node {
    int sum;
    int prod;
    vector<int> exp;
};

Node tree[1 + 4 * MAXN];
int power[11][20 * MAXN];

void precompute() {
    for (int i = 0; i < primes.size(); i++) {
        power[i][0] = 1;
        for (int j = 1; j < 20 * MAXN; j++) {
            power[i][j] = 1LL * power[i][j - 1] * primes[i] % mod;
        }
    }
}

Node empty() {
    return {0, 1, vector<int> (primes.size(), 0)};
}

int eval(Node &node) {
    int ans = node.sum;
    ans = 1LL * ans * node.prod % mod;
    for (int i = 0; i < primes.size(); i++) {
        ans = 1LL * ans * power[i][node.exp[i]] % mod;
    }
    return ans;
}

void build(int node, int left, int right) {
    tree[node] = empty();
    if (left == right) {
        tree[node].sum = v[left];
        for (int i = 0; i < primes.size(); i++) {
            while (tree[node].sum % primes[i] == 0) {
                tree[node].sum /= primes[i];
                tree[node].exp[i]++;
            }
        }
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    tree[node].sum = (eval(tree[2 * node]) + eval(tree[2 * node + 1])) % mod;
}

void push(Node &node, Node &son) {
    son.prod = 1LL * son.prod * node.prod % mod;
    for (int i = 0; i < primes.size(); i++) {
        son.exp[i] += node.exp[i];
    }
}

void propagate(Node &node, Node &left, Node &right) {
    if (node.prod != 1 || node.exp != vector<int> (primes.size(), 0)) {
        node.sum = eval(node);
        push(node, left);
        push(node, right);
        node.prod = 1;
        node.exp = vector<int> (primes.size(), 0);
    }
}

void update(int node, int left, int right, int from, int to, int mul, vector<int> &add) {
    if (from <= left && right <= to) {
        tree[node].prod = 1LL * tree[node].prod * mul % mod;
        for (int i = 0; i < primes.size(); i++) {
            tree[node].exp[i] += add[i];
        }
        return;
    }
    propagate(tree[node], tree[2 * node], tree[2 * node + 1]);
    int middle = (left + right) / 2;
    if (from <= middle) {
        update(2 * node, left, middle, from, to, mul, add);
    }
    if (middle + 1 <= to) {
        update(2 * node + 1, middle + 1, right, from, to, mul, add);
    }
    tree[node].sum = (eval(tree[2 * node]) + eval(tree[2 * node + 1])) % mod;
}

int query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return eval(tree[node]);
    }
    propagate(tree[node], tree[2 * node], tree[2 * node + 1]);
    int middle = (left + right) / 2;
    int ans = 0;
    if (from <= middle) {
        ans += query(2 * node, left, middle, from, to);
    }
    if (middle + 1 <= to) {
        ans += query(2 * node + 1, middle + 1, right, from, to);
    }
    return ans % mod;
}

pair<int, vector<int> > decompose(int x) {
    int mul = x;
    vector<int> add(primes.size(), 0);
    for (int i = 0; i < primes.size(); i++) {
        while (mul % primes[i] == 0) {
            add[i]++;
            mul /= primes[i];
        }
    }
    return {mul, add};
}

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = 1LL * answer * base % mod;
        }
        base = 1LL * base * base % mod;
        power >>= 1;
    }
    return answer;
}

int main() {
    timeBegin();
    InputReader cin;
    //ofstream cout("output.out");
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    srand(time(0));
    int n;
    cin >> n >> mod;
    primes = getPrimes(mod);
    precompute();
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            pair<int, vector<int> > val = decompose(x);
            update(1, 1, n, l, r, val.first, val.second);
        } else if (type == 2) {
            int p, x;
            cin >> p >> x;
            pair<int, vector<int> > val = decompose(x);
            val.first = raiseToPower(val.first, phi - 1);
            for (int i = 0; i < primes.size(); i++) {
                val.second[i] *= -1;
            }
            update(1, 1, n, p, p, val.first, val.second);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}