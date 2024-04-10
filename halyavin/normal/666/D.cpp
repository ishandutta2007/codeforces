#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

struct ipoint {
  int x;
  int y;
  ipoint() : x(0), y(0) { }
  ipoint(int x, int y) : x(x), y(y) { }
};

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

std::array<int, 4> getPerm(int p) {
  std::array<int, 4> perm;
  std::iota(perm.begin(), perm.end(), 0);
  for (int i = 2; i <= 4; i++) {
    std::swap(perm[p % i], perm[i - 1]);
    p /= i;
  }
  return perm;
};

int getT(std::array<ipoint, 4>& bots, std::array<ipoint, 4>& dbots) {
  std::vector<std::array<int, 6>> eqs(8);
  eqs[0][5] = bots[1].y - bots[0].y;
  eqs[0][1] = dbots[1].y;
  eqs[0][0] = -dbots[0].y;
  eqs[1][5] = bots[1].x - bots[0].x;
  eqs[1][1] = dbots[1].x;
  eqs[1][0] = -dbots[0].x;
  eqs[1][4] = -1;

  eqs[2][5] = bots[3].y - bots[2].y;
  eqs[2][3] = dbots[3].y;
  eqs[2][2] = -dbots[2].y;
  eqs[3][5] = bots[3].x - bots[2].x;
  eqs[3][3] = dbots[3].x;
  eqs[3][2] = -dbots[2].x;
  eqs[3][4] = -1;

  eqs[4][5] = bots[2].x - bots[0].x;
  eqs[4][2] = dbots[2].x;
  eqs[4][0] = -dbots[0].x;
  eqs[5][5] = bots[2].y - bots[0].y;
  eqs[5][2] = dbots[2].y;
  eqs[5][0] = -dbots[0].y;
  eqs[5][4] = -1;

  eqs[6][5] = bots[3].x - bots[1].x;
  eqs[6][3] = dbots[3].x;
  eqs[6][1] = -dbots[1].x;
  eqs[7][5] = bots[3].y - bots[1].y;
  eqs[7][3] = dbots[3].y;
  eqs[7][1] = -dbots[1].y;
  eqs[7][4] = -1;

  int crow = 0;
  for (int i = 0; i < 5; i++) {
    while (true) {
      int minI = -1;
      int optI = 1000000000;
      for (int j = crow; j < (int) eqs.size(); j++) {
        if (eqs[j][i] != 0 && abs(eqs[j][i]) < optI) {
          minI = j;
          optI = abs(eqs[j][i]);
        }
      }
      if (minI == -1) {
        break;
      }
      std::swap(eqs[crow], eqs[minI]);
      bool good = true;
      for (size_t j = crow + 1; j < eqs.size(); j++) {
        int c = eqs[j][i] / eqs[crow][i];
        for (size_t k = i; k < eqs[j].size(); k++) {
          eqs[j][k] -= c * eqs[crow][k];
        }
        if (eqs[j][i] != 0) {
          good = false;
        }
      }
      if (good) {
        crow++;
        break;
      }
    }
  }
  for (size_t i = crow; i < eqs.size(); i++) {
    if (eqs[i][5] != 0) {
      return -1;
    }
  }
  crow--;
  if (eqs[crow][5] % eqs[crow][4] != 0) {
    return -1;
  }
  if (eqs[crow][4] == 0) {
    return -1;
  }
  std::array<int, 5> solution = {};
  solution[4] = -eqs[crow][5] / eqs[crow][4];
  crow--;
  if (eqs[crow][2] == 0) {
    for (int i = 3; i >= 0; i--) {
      solution[i] = -eqs[i][5];
      for (int j = i + 1; j < 5; j++) {
        solution[i] -= solution[j] * eqs[i][j];
      }
      if (solution[i] % eqs[i][i] != 0) {
        return -1;
      }
      solution[i] /= eqs[i][i];
    }
  } else {
    std::array<int, 5> dsolution = {};
    dsolution[3] = 1;
    for (int i = 2; i >= 0; i--) {
      solution[i] = -eqs[i][5];
      for (int j = i + 1; j < 5; j++) {
        solution[i] -= solution[j] * eqs[i][j];
        dsolution[i] -= dsolution[j] * eqs[i][j];
      }
      if (solution[i] % eqs[i][i] != 0) {
        return -1;
      }
      if (dsolution[i] % eqs[i][i] != 0) {
        return -1;
      }
      solution[i] /= eqs[i][i];
      dsolution[i] /= eqs[i][i];
      if (std::abs(dsolution[i]) != 1) {
        return -1;
      }
    }
    int maxPos = 0;
    int maxNeg = 0;
    for (int i = 0; i <= 2; i++) {
      if (dsolution[i] > 0) {
        maxPos = std::max(maxPos, solution[i]);
        maxNeg = std::max(maxNeg, -solution[i]);
      } else {
        maxPos = std::max(maxPos, -solution[i]);
        maxNeg = std::max(maxNeg, solution[i]);
      }
    }
    int t = (maxNeg - maxPos) / 2;
    for (int i = 0; i <= 3; i++) {
      solution[i] += t * dsolution[i];
    }
  }
  for (int i = 0; i < 4; i++) {
    bots[i].x += dbots[i].x * solution[i];
    bots[i].y += dbots[i].y * solution[i];
  }
  int t = 0;
  for (int i = 0; i < 4; i++) {
    t = std::max(t, std::abs(solution[i]));
  }
  return t;
}

int solve(std::array<ipoint, 4>& bots) {
  std::array<ipoint, 4> dbots = {};
  int optT = 1000000000;
  std::array<ipoint, 4> optBots = bots;
  for (int dir = 0; dir < 2 * 2 * 2 * 2; dir++) {
    int cdir = dir;
    for (int i = 0; i < 4; i++) {
      dbots[i].x = dx[cdir % 2];
      dbots[i].y = dy[cdir % 2];
      cdir /= 2;
    }
    for (int p = 0; p < 24; p++) {
      std::array<int, 4> perm = getPerm(p);
      std::array<ipoint, 4> pbots;
      std::array<ipoint, 4> pdbots;
      for (int i = 0; i < 4; i++) {
        pbots[i] = bots[perm[i]];
        pdbots[i] = dbots[perm[i]];

      }
      int curT = getT(pbots, pdbots);
      if (curT >= 0 && curT < optT) {
        optT = curT;
        for (int i = 0; i < 4; i++) {
          optBots[perm[i]] = pbots[i];
        }
      }
    }
  }
  if (optT == 1000000000) {
    optT = -1;
  }
  bots = optBots;
  return optT;
}

void run(std::istream& in, std::ostream& out) {
  int t;
  in >> t;
  for (int i = 0; i < t; i++) {
    std::array<ipoint, 4> bots = {};
    for (int j = 0; j < 4; j++) {
      in >> bots[j].x >> bots[j].y;
    }
    int time = solve(bots);
    out << time << std::endl;
    if (time >= 0) {
      for (int j = 0; j < 4; j++) {
        out << bots[j].x << " " << bots[j].y << std::endl;
      }
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  std::cout.flush();
  return 0;
}