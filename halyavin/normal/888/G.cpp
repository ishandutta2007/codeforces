#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

template<class It>
int getDist(It first1, It last1, It first2, It last2, int bit) {
    if (bit == -1) {
        return 0;
    }
    It middle1 = std::partition(first1, last1, [bit](int a) {
        return (a >> bit) & 1;
    });
    It middle2 = std::partition(first2, last2, [bit](int a) {
        return (a >> bit) & 1;
    });
    int res = 1 << (bit + 1);
    if (middle1 != first1 && middle2 != first2) {
        res = std::min(res, getDist(first1, middle1, first2, middle2, bit - 1));
    }
    if (middle1 != last1 && middle2 != last2) {
        res = std::min(res, getDist(middle1, last1, middle2, last2, bit - 1));
    }
    if (res == (1 << (bit + 1))) {
        if (first1 != middle1 && middle2 != last2) {
            res = std::min(res, (1 << bit) + getDist(first1, middle1, middle2, last2, bit - 1));
        } else if (middle1 != last1 && first2 != middle2) {
            res = std::min(res, (1 << bit) + getDist(middle1, last1, first2, middle2, bit - 1));
        }
    }
    return res;
}

template<class It>
int64_t getAns(It first, It last, int bit) {
    if (bit == -1) {
        return 0;
    }
    It middle = std::partition(first, last, [bit](int a) {
        return (a >> bit) & 1;
    });
    if (middle == first || middle == last) {
        return getAns(first, last, bit - 1);
    }
    int64_t res = getAns(first, middle, bit - 1) + getAns(middle, last, bit - 1);
    return res + (1 << bit) + getDist(first, middle, middle, last, bit - 1);
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    out << getAns(as.begin(), as.end(), 29) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}