#include <iostream>
#include <cmath>
#include <array>

std::array<double, 2> calcFirstPart(double accel, double max_speed, double speed_bound, double dist) {
    speed_bound = std::min(speed_bound, max_speed);
    double max_speed1 = std::sqrt(2 * accel * dist);
    if (max_speed1 < speed_bound) {
        return std::array<double, 2> {std::sqrt(2 * dist / accel), max_speed1};
    }
    double time_diff = speed_bound / accel;
    double q1 = 2 * time_diff;
    double q0 = time_diff * time_diff / 2 - dist / accel;
    double time_slow = (-q1 + std::sqrt(q1 * q1 - 4 * q0)) / 2;
    double time_fast = time_slow + time_diff;
    max_speed1 = time_fast * accel;
    if (max_speed1 < max_speed) {
        return std::array<double, 2> {time_slow + time_fast, speed_bound};
    }
    time_fast = max_speed / accel;
    time_slow = (max_speed - speed_bound) / accel;
    double dist1 = accel * time_fast * time_fast / 2;
    dist1 += time_slow * max_speed - accel * time_slow * time_slow / 2;
    double time_steady = (dist - dist1) / max_speed;
    return std::array<double, 2> {time_slow + time_steady + time_fast, speed_bound};
}

double calcSecondPart(double accel, double max_speed, double speed, double dist) {
    double time_fast = (max_speed - speed) / accel;
    double dist_fast = speed * time_fast + accel * time_fast * time_fast / 2;
    if (dist > dist_fast) {
        return time_fast + (dist - dist_fast) / max_speed;
    }
    return (-speed + std::sqrt(speed * speed + 2 * dist * accel)) / accel;
}

void run(std::istream &in, std::ostream &out) {
    double a, v, w, d, l;
    in >> a >> v;
    in >> l >> d >> w;
    std::array<double, 2> solve1 = calcFirstPart(a, v, w, d);
    double solve2 = calcSecondPart(a, v, solve1[1], l - d);
    out.precision(9);
    out << std::fixed << (solve1[0] + solve2) << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}