#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

template <class T, size_t Width, size_t Height>
struct Matrix {
    array<T, Width * Height> data_;

    T& operator()(size_t y, size_t x) {
        return data_[y * Width + x];
    }

    T* row(size_t y) {
        return &data_[y * Width];
    }
};

template <class T>
struct MinQueue {
    vector<pair<T, T>> s1;
    vector<pair<T, T>> s2;

    static void push_to_stack(vector<pair<T, T>>& s, T val) {
        T m = s.empty() ? val : std::min(val, s.back().second);
        s.emplace_back(val, m);
    }

    T min() const {
        if (s1.empty() || s2.empty()) {
            return s1.empty() ? s2.back().second : s1.back().second;
        }
        return std::min(s1.back().second, s2.back().second);
    }

    void push(T val) {
        push_to_stack(s1, val);
    }

    void pop() {
        if (s2.empty()) {
            for (auto it = rbegin(s1); it != rend(s1); ++it) {
                push_to_stack(s2, it->first);
            }
            s1.clear();
        }
        s2.pop_back();
    }

    void clear() {
        s1.clear();
        s2.clear();
    }
};

Matrix<int, 3000, 3000> mat;

int main() {
    ios::sync_with_stdio(false);

    size_t n, m, a, b;
    cin >> n >> m >> a >> b;

    int g, x, y, z;
    cin >> g >> x >> y >> z;

    MinQueue<int> q;
    for (size_t i = 0; i < n; ++i) {
        q.clear();
        for (size_t j = 0; j < b - 1; ++j) {
            q.push(g);
            g = (((int64_t)g * x) + y) % z;
        }
        for (size_t j = b - 1; j < m; ++j) {
            q.push(g);
            g = (((int64_t)g * x) + y) % z;
            mat(i, j - (b - 1)) = q.min();
            q.pop();
        }
    }

    int64_t sum = 0;
    for (size_t j = 0; j <= m - b; ++j) {
        q.clear();
        for (size_t i = 0; i < a - 1; ++i) {
            q.push(mat(i, j));
        }
        for (size_t i = a - 1; i < n; ++i) {
            q.push(mat(i, j));
            sum += q.min();
            q.pop();
        }
    }

    cout << sum << '\n';

    return 0;
}