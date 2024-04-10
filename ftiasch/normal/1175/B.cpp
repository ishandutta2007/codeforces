#include <bits/stdc++.h>

using Long = unsigned long long;

const Long LIMIT = static_cast<Long>(1) << 32;

void add(Long &x, Long a) { x = std::min(x + a, LIMIT); }

void mul(Long &x, Long a) {
  if (x >= LIMIT || a >= LIMIT) {
    x = LIMIT;
  } else {
    x = std::min(x * a, LIMIT);
  }
}

struct Frame {
  Long sum, loop;
};

int main() {
  int q;
  scanf("%d", &q);
  std::vector<Frame> stack{Frame{0, 1}};
  while (q--) {
    char buffer[4];
    scanf("%s", buffer);
    switch (*buffer) {
    case 'f': {
      int n;
      scanf("%d", &n);
      stack.push_back(Frame{0, static_cast<Long>(n)});
      break;
    }
    case 'e': {
      auto [sum, loop] = stack.back();
      stack.pop_back();
      mul(sum, loop);
      add(stack.back().sum, sum);
      break;
    }
    case 'a': {
      add(stack.back().sum, 1);
      break;
    }
    }
  }
  assert(stack.size() == 1);
  Long sum = stack.back().sum;
  if (sum >= LIMIT) {
      puts("OVERFLOW!!!");
  } else {
      printf("%u\n", static_cast<unsigned int>(sum));
  }
}