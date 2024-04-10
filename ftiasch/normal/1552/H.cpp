#include <bits/stdc++.h>

struct Point {
  int x, y;
};

struct Mock {
  int ask(const std::vector<Point> &ps) {
    fprintf(stderr, "ask\n");
    int result = 0;
    for (auto &&p : ps) {
      result += x0 <= p.x && p.x <= x1 && y0 <= p.y && p.y <= y1;
    }
    return result;
  }

  void answer(int p) {
    assert(p == 2 * (x1 - x0 + y1 - y0));
    fprintf(stderr, "OK\n");
  }

  int x0, y0, x1, y1;
};

struct IO {
  int ask(const std::vector<Point> &ps) {
    std::cout << "? " << ps.size() << "\n";
    for (auto &&p : ps) {
      std::cout << p.x << " " << p.y << " ";
    }
    std::cout << "\n" << std::flush;
    int result;
    std::cin >> result;
    return result;
  }

  void answer(int p) { std::cout << "! " << p << std::flush; }
};

const int M = 200;

template <typename Interactor> void solve(Interactor &&io) {
  auto f = [&](int d) {
    std::vector<Point> ps;
    for (int x = d; x <= M; x += d) {
      for (int y = 1; y <= M; ++y) {
        ps.push_back(Point{x, y});
      }
    }
    return io.ask(ps);
  };

  int buffer[9];
  buffer[0] = f(1);
  buffer[8] = 0;
  int low = 0;
  int high = 8;
  // [low, high)
  // buffer[low], buffer[high] are known
  while (low + 1 < high) {
    int middle = (low + high) >> 1;
    buffer[middle] = f(1 << middle);
    if ((buffer[middle] << middle) == buffer[0]) {
      low = middle;
    } else {
      high = middle;
    }
  }
  int h = std::abs(2 * buffer[low + 1] - buffer[low]);
  int w = buffer[0] / h;
  io.answer(2 * ((w - 1) + (h - 1)));
}

int main() {
  // int x0, y0, x1, y1;
  // scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
  // solve<Mock>(Mock{x0, y0, x1, y1});
  solve<IO>(IO());
}