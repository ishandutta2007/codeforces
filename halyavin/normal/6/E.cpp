#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <functional>

void run(std::istream &in, std::ostream &out) {
    int n, k;
    in >> n >> k;
    int max_length = 0;
    std::vector<std::pair<int, int>> answer;
    std::function<void(int, int)> update_answer = [&](int from, int to) {
        int len = to - from;
        if (len > max_length) {
            max_length = len;
            answer.clear();
            answer.emplace_back(from + 1, to);
        } else if (len == max_length) {
            answer.emplace_back(from + 1, to);
        }
    };
    std::set<std::pair<int, int>> cur_books;
    std::vector<std::pair<int, int>> book_info(n);
    int last = 0;
    for (int i = 0; i < n; i++) {
        std::pair<int, int>& cur_book = book_info[i];
        in >> cur_book.first;
        cur_book.second = i;
        int next_last = last;
        while (!cur_books.empty() && cur_books.begin()->first < cur_book.first - k) {
            update_answer(cur_books.begin()->second, i);
            next_last = std::max(next_last, cur_books.begin()->second);
            cur_books.erase(cur_books.begin());
        }
        while (!cur_books.empty() && (--cur_books.end())->first > cur_book.first + k) {
            auto it = --cur_books.end();
            update_answer(it->second, i);
            next_last = std::max(next_last, it->second);
            cur_books.erase(it);
        }
        for (int j = last; j < next_last; j++) {
            auto it = cur_books.find(book_info[j]);
            if (it != cur_books.end()) {
                update_answer(it->second, i);
                cur_books.erase(it);
            }
        }
        last = next_last;
        cur_books.insert(cur_book);
    }
    for (auto book : cur_books) {
        update_answer(book.second, n);
    }
    out << max_length << " " << answer.size() << std::endl;
    for (auto &interval : answer) out << interval.first << " " << interval.second << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}