#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <limits>

int opt;

template<typename T>
T div_up(T a, T b) {
    return (a + b - 1) / b;
}

size_t subtract(size_t from, size_t val, size_t count) {
    if (val * count > from) return 0;
    return from - val * count;
}

void run(std::istream &in, std::ostream &out) {
    size_t n;
    size_t a, b;
    in >> n >> a >> b;
    assert(n >= 3);
    std::vector<size_t> h(n);
    for (size_t &hp : h) {
        in >> hp;
        hp++;
    }
    using table = std::array<std::array<size_t, 17>, 17>;
    std::vector<table> dyn(n - 1);
    std::vector<table> next(n - 1);
    table &last = dyn[n - 2];
    table &last_next = next[n - 2];
    for (size_t i = 0; i < last.size(); i++) {
        for (size_t j = 0; j < last[i].size(); j++) {
            last[i][j] = std::max(std::max(div_up(i, b), div_up(j, a)), div_up(h[n - 1], b));
            last_next[i][j] = last[i][j];
        }
    }
    for (size_t place = n - 3; place >= 1; place--) {
        table &cur = dyn[place];
        table &cur_next = next[place];
        for (size_t i = 0; i < last.size(); i++) {
            for (size_t j = 0; j < last[i].size(); j++) {
                cur[i][j] = std::numeric_limits<size_t>::max();
                for (size_t k = div_up(i, b); k <= 16; k++) {
                    size_t next_i = subtract(j, a, k);
                    size_t next_j = subtract(h[place+1], b, k);
                    size_t cur_value = dyn[place + 1][next_i][next_j] + k;
                    if (cur_value < cur[i][j]) {
                        cur[i][j] = cur_value;
                        cur_next[i][j] = k;
                    }
                }
            }
        }
    }
    std::vector<size_t> answer;
    size_t cur_i = h[0];
    size_t cur_j = h[1];
    for (size_t place = 1; place <= n-2; place++) {
        size_t v = next[place][cur_i][cur_j];
        answer.insert(answer.end(), v, place + 1);
        cur_i = subtract(cur_j, a, v);
        cur_j = subtract(h[place+1], b, v);
    }
    out << answer.size() << std::endl;
    for (size_t place : answer) out << place << " ";
    out << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}