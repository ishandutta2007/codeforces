#include <iostream>
#include <array>
#include <cassert>

void run(std::istream &in, std::ostream &out) {
    std::array<std::string, 2> player_names {"first", "second"};
    std::array<std::array<int, 3>, 3> field;
    for (int i = 0; i < 3; i++) {
        std::string line;
        in >> line;
        assert(line.length() == 3);
        for (int j = 0; j < 3; j++) {
            switch (line[j]) {
                case 'X':
                    field[i][j] = 1;
                    break;
                case '0':
                    field[i][j] = 2;
                    break;
                default:
                    field[i][j] = 0;
                    break;
            }
        }
    }
    std::array<int, 2> nums{0, 0};
    for (auto &row : field) {
        for (auto &cell : row) {
            if (cell > 0) nums[cell - 1]++;
        }
    }
    if (nums[0] < nums[1] || nums[0] > nums[1] + 1) {
        out << "illegal" << std::endl;
        return;
    }
    std::array<bool, 2> won{false, false};
    for (int player = 1; player <= 2; player++) {
        for (int i = 0; i < 3; i++) {
            bool good = true;
            for (int j = 0; j < 3; j++) {
                if (field[i][j] != player) good = false;
            }
            if (good) {
                won[player - 1] = true;
                break;
            }
            good = true;
            for (int j = 0; j < 3; j++) {
                if (field[j][i] != player) good = false;
            }
            if (good) {
                won[player - 1] = true;
                break;
            }
        }
        bool good = true;
        for (int i = 0; i < 3; i++) {
            if (field[i][i] != player) good = false;
        }
        if (good) {
            won[player - 1] = true;
            break;
        }
        good = true;
        for (int i = 0; i < 3; i++) {
            if (field[i][2 - i] != player) good = false;
        }
        if (good) {
            won[player - 1] = true;
            break;
        }
    }
    if (won[0] && won[1]) {
        out << "illegal" << std::endl;
        return;
    }
    if (!won[0] && !won[1] && nums[0] + nums[1] == 9) {
        out << "draw" << std::endl;
        return;
    }
    int next_turn = nums[0] - nums[1];
    int prev_turn = 1 - next_turn;
    if (won[prev_turn]) {
        out << "the " << player_names[prev_turn] << " player won" << std::endl;
        return;
    }
    if (won[next_turn]) {
        out << "illegal" << std::endl;
        return;
    }
    out << player_names[next_turn] << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}