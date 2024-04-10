#include <fstream>
#include <iostream>
#include <tuple>
#include <cassert>
#include <vector>
#include <cmath>

std::tuple<int, int> getCoords(const std::string &coord) {
    assert(coord.length() == 2);
    return std::make_tuple(coord[0]-'a', coord[1]-'1');
}

void run(std::istream& in, std::ostream& out) {
    std::string from;
    std::string to;
    in >> from >> to;
    auto from_cell = getCoords(from);
    auto to_cell = getCoords(to);
    std::vector<std::string> answer;
    if (std::get<0>(from_cell) != std::get<0>(to_cell) &&
            std::get<1>(from_cell) != std::get<1>(to_cell)) {
        int diff0 = std::get<0>(to_cell) - std::get<0>(from_cell);
        int diff1 = std::get<1>(to_cell) - std::get<1>(from_cell);
        int count = std::min(std::abs(diff0), std::abs(diff1));
        int dir0 = std::signbit(diff0) ? -1 : 1;
        int dir1 = std::signbit(diff1) ? -1 : 1;
        std::string move = std::signbit(diff0) ? "L" : "R";
        move.append(std::signbit(diff1) ? "D" : "U");
        answer.insert(answer.end(), count, move);
        std::get<0>(from_cell) += dir0 * count;
        std::get<1>(from_cell) += dir1 * count;
    }
    if (std::get<0>(from_cell) != std::get<0>(to_cell)) {
        int diff0 = std::get<0>(to_cell) - std::get<0>(from_cell);
        int count = std::abs(diff0);
        std::string move = std::signbit(diff0) ? "L" : "R";
        answer.insert(answer.end(), count, move);
    }
    if (std::get<1>(from_cell) != std::get<1>(to_cell)) {
        int diff1 = std::get<1>(to_cell) - std::get<1>(from_cell);
        int count = std::abs(diff1);
        std::string move = std::signbit(diff1) ? "D" : "U";
        answer.insert(answer.end(), count, move);
    }
    out << answer.size() << std::endl;
    for (auto& move : answer) {
        out << move << std::endl;
    }
}

int main() {
    run(std::cin, std::cout);
    return 0;
}