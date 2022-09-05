#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cassert>
#include <algorithm>
#include <ctype.h>

enum MajorOperation {
    BAD = 0,
    PLUS = 1,
    MULT = 2,
    TERM = 3
};

size_t next_bracket(const std::string &expression, size_t pos) {
    int level = 1;
    for (size_t i = pos + 1; i < expression.length(); i++) {
        if (expression[i] == '(') level++;
        if (expression[i] == ')') level--;
        if (level == 0) return i;
    }
    assert(false);
}

MajorOperation parse(const std::unordered_map<std::string, MajorOperation> &defines,
        const std::string &expression);

MajorOperation parse_term(const std::unordered_map<std::string, MajorOperation> &defines,
        size_t &pos, const std::string &expression) {
    while (expression[pos] == '+' || expression[pos] == '-') {
        pos++;
    }
    if (expression[pos] == '(') {
        size_t next_pos = next_bracket(expression, pos);
        std::string term = expression.substr(pos + 1, next_pos - pos - 1);
        pos = next_pos + 1;
        return parse(defines, term) == BAD ? BAD : TERM;
    }
    size_t next_pos = pos;
    while (next_pos < expression.length() && isalnum(expression[next_pos])) next_pos++;
    std::string name = expression.substr(pos, next_pos - pos);
    auto it = defines.find(name);
    pos = next_pos;
    if (it != defines.end()) {
        return it->second;
    }
    return TERM;
}

MajorOperation parse(const std::unordered_map<std::string, MajorOperation> &defines,
        const std::string &expression) {
    MajorOperation result = TERM;
    size_t pos = 0;
    char prev_op = 0;
    while (pos < expression.length()) {
        MajorOperation term = parse_term(defines, pos, expression);
        if (term == BAD) return BAD;
        if (prev_op == '/' && term != TERM) return BAD;
        if (prev_op == '*' && term == PLUS) return BAD;
        if (prev_op == '-' && term == PLUS) return BAD;
        result = std::min(result, term);
        if (pos == expression.length()) return result;
        char op = expression[pos++];
        switch (op) {
            case '*':
            case '/':
                result = std::min(result, MULT);
                if (term < MULT) return BAD;
                break;
            case '+':
            case '-':
                result = std::min(result, PLUS);
                break;
            default:
                assert(false);
        }
        prev_op = op;
    }
    return result;
}

void remove_spaces(std::string &def) {
    auto it = stable_partition(def.begin(), def.end(), [](char c) {
        return c != ' ';
    });
    def.erase(it, def.end());
}

void run(std::istream &in, std::ostream &out) {
    std::string num;
    std::getline(in, num);
    int n;
    std::istringstream(num) >> n;
    std::unordered_map<std::string, MajorOperation> defines;
    for (int i = 0; i < n; i++) {
        std::string def;
        std::getline(in, def);
        std::istringstream line(def);
        char first;
        line >> first;
        assert(first == '#');
        std::string word;
        line >> word;
        assert(word == "define");
        line >> word;
        def = def.substr(line.tellg());
        remove_spaces(def);
        MajorOperation res = parse(defines, def);
        defines[word] = res;
    }
    std::string expr;
    std::getline(in, expr);
    remove_spaces(expr);
    if (parse(defines, expr) == BAD) {
        out << "Suspicious" << std::endl;
    } else {
        out << "OK" << std::endl;
    }
}


int main() {
    run(std::cin, std::cout);
    return 0;
}