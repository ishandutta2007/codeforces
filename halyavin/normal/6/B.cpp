#include <iostream>
#include <vector>
#include <array>

int add_char(std::array<bool, 26> &stat, char c) {
    if (c == '.') return 0;
    if (stat[c - 'A']) return 0;
    stat[c - 'A'] = true;
    return 1;
}

void run(std::istream &in, std::ostream &out) {
    int n, m;
    char president;
    in >> n >> m >> president;
    std::vector<std::string> field;
    for (int i = 0; i < n; i++) {
        std::string row;
        in >> row;
        field.push_back(row);
    }
    std::array<bool, 26> stat{};
    add_char(stat, president);
    int answer = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == president) answer += add_char(stat, field[i+1][j]);
            if (field[i+1][j] == president) answer += add_char(stat, field[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1;j++) {
            if (field[i][j] == president) answer += add_char(stat, field[i][j+1]);
            if (field[i][j+1] == president) answer += add_char(stat, field[i][j]);
        }
    }
    out << answer << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}