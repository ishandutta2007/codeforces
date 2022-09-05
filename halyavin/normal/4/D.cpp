#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

void run(std::istream &in, std::ostream &out) {
    int n, w, h;
    in >> n >> w >> h;
    std::vector<std::array<int, 3>> rects;
    for (int i = 1; i <= n; i++) {
        int width, height;
        in >> width >> height;
        if (width > w && height > h) rects.push_back(std::array<int, 3>{width, height, i});
    }
    if (rects.size() == 0) {
        out << 0 << std::endl;
        return;
    }
    std::sort(rects.begin(), rects.end(), std::greater<std::array<int, 3>>());
    std::vector<int> maxChains;
    std::vector<int> prevs;
    int maxAnswer = 0;
    int maxIndex = 0;
    for (size_t i = 0; i < rects.size(); i++) {
        int maxChain = 0;
        int prev = -1;
        for (size_t j = 0; j < i; j++) {
            if (rects[j][0] > rects[i][0] && rects[j][1] > rects[i][1]) {
                if (maxChains[j] > maxChain) {
                    maxChain = maxChains[j];
                    prev = j;
                }
            }
        }
        maxChain++;
        maxChains.push_back(maxChain);
        prevs.push_back(prev);
        if (maxChain > maxAnswer) {
            maxAnswer = maxChain;
            maxIndex = i;
        }
    }
    out << maxAnswer << std::endl;
    while (maxIndex >= 0) {
        out << rects[maxIndex][2] << " ";
        maxIndex = prevs[maxIndex];
    }
    out << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}