#include <iostream>
#include <vector>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> data(n);
    for (int i = 0; i < n; i++) in >> data[i];
    int i = 0;
    int j = n - 1;
    int timeA = 0, timeB = 0;
    while (j >= i) {
        if (timeA <= timeB) {
            timeB -= timeA;
            timeA = data[i];
            i++;
        } else {
            timeA -= timeB;
            timeB = data[j];
            j--;
        }
    }
    out << i << " " << n - i << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}