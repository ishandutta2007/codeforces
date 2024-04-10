#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int pop_equal_elements(std::stack<int>* stack) {
    int result = 0;
    int top_element = stack->top();
    while (!stack->empty() && stack->top() == top_element) {
        result++;
        stack->pop();
    }
    return result;
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> heights(n);
    int64_t answer = 0;
    for (int i = 0; i < n; i++) {
        in >> heights[i];
    }
    auto max_height = std::max_element(heights.begin(), heights.end());
    std::rotate(heights.begin(), max_height, heights.end());
    std::stack<int> height_stack;
    int max_value = heights[0];
    height_stack.push(heights[0]);
    for (size_t i = 1; i < heights.size(); i++) {
        while (height_stack.top() < heights[i]) {
            int num = pop_equal_elements(&height_stack);
            answer += num * int64_t(num + 3) / 2;
        }
        height_stack.push(heights[i]);
    }
    while (height_stack.top() < max_value) {
        int num = pop_equal_elements(&height_stack);
        if (height_stack.size() > 1) {
            answer += num * int64_t(num + 3) / 2;
        } else {
            answer += num * int64_t(num + 1) / 2;
        }
    }
    int num = height_stack.size();
    answer += num * int64_t(num - 1) / 2;
    out << answer << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}