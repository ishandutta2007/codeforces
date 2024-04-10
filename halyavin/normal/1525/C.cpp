#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

struct Robot {
    int x = 0;
    int dir = 0;
    int index = 0;

    Robot() {}

    Robot(int x, int dir, int index) :
            x(x), dir(dir), index(index) {}
};

struct Solution {
    int n, m;
    std::vector<Robot> robots;
    std::vector<int> answer;

    void solve(const std::vector<Robot>& seq) {
        std::vector<Robot> stack;
        for (const auto& robot : seq) {
            if (!stack.empty() && stack.back().dir == 1 && robot.dir == -1) {
                int t = (robot.x - stack.back().x) / 2;
                answer[stack.back().index] = t;
                answer[robot.index] = t;
                stack.pop_back();
            } else {
                stack.push_back(robot);
            }
        }
        while (stack.size() >= 2) {
            auto& last1 = stack[stack.size() - 1];
            auto& last2 = stack[stack.size() - 2];
            if (last1.dir == 1 && last2.dir == 1) {
                last1.x = 2 * m - last1.x;
                int t = (last1.x - last2.x) / 2;
                answer[last1.index] = t;
                answer[last2.index] = t;
                stack.pop_back();
                stack.pop_back();
            } else {
                break;
            }
        }
        std::optional<Robot> lastRobot;
        if (!stack.empty() && stack.back().dir == 1) {
            lastRobot = stack.back();
            stack.pop_back();
        }
        for (size_t i = 0; i + 2 <= stack.size(); i+=2) {
            auto& front1 = stack[i];
            auto& front2 = stack[i + 1];
            front1.x = -front1.x;
            int t = (front2.x - front1.x) / 2;
            answer[front1.index] = t;
            answer[front2.index] = t;
        }
        std::optional<Robot> firstRobot;
        if ((stack.size() & 1u) != 0) {
            firstRobot = stack.back();
        }
        if (lastRobot.has_value() && firstRobot.has_value()) {
            lastRobot->x = 2 * m - lastRobot->x;
            firstRobot->x = -firstRobot->x;
            int t = (lastRobot->x - firstRobot->x) / 2;
            answer[firstRobot->index] = t;
            answer[lastRobot->index] = t;
        }
    }

    void run(std::istream& in, std::ostream& out) {
        int t;
        in >> t;
        for (int test = 0; test < t; test++) {
            in >> n >> m;
            robots.resize(n);
            for (int i = 0; i < n; i++) {
                robots[i].index = i;
                in >> robots[i].x;
            }
            for (int i = 0; i < n; i++) {
                char c;
                in >> c;
                robots[i].dir = (c == 'R') ? 1 : -1;
            }
            std::sort(robots.begin(), robots.end(), [](const auto& left, const auto& right){
                return left.x < right.x;
            });
            answer.assign(n, -1);
            std::vector<Robot> even, odd;
            for (const auto& robot : robots) {
                if ((robot.x & 1) != 0) {
                    odd.push_back(robot);
                } else {
                    even.push_back(robot);
                }
            }
            solve(even);
            solve(odd);
            for (int i = 0; i < n; i++) {
                out << answer[i] << " ";
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}