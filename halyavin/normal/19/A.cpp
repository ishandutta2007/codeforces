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
#include <map>
#include <tuple>

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::map<std::string, int> teamIndex;
  std::vector<std::string> teamNames;
  for (int i = 0; i < n; i++) {
    std::string team;
    in >> team;
    teamNames.push_back(team);
    teamIndex[team] = i;
  }
  std::vector<std::tuple<int, int, int, int>> teamStatus(n);
  for (int i = 0; i < n; i++) {
    std::get<3>(teamStatus[i]) = i;
  }
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    std::string match;
    in >> match;
    int pos = match.find('-');
    std::string team1 = match.substr(0, pos);
    std::string team2 = match.substr(pos + 1);
    int i1 = teamIndex[team1];
    int i2 = teamIndex[team2];
    std::string result;
    in >> result;
    pos = result.find(':');
    int balls1 = atoi(result.substr(0, pos).c_str());
    int balls2 = atoi(result.substr(pos + 1).c_str());
    if (balls1 > balls2) {
      std::get<0>(teamStatus[i1]) += 3;
    } else if (balls1 == balls2) {
      std::get<0>(teamStatus[i1])++;
      std::get<0>(teamStatus[i2])++;
    } else {
      std::get<0>(teamStatus[i2]) += 3;
    }
    std::get<1>(teamStatus[i1])+=balls1 - balls2;
    std::get<1>(teamStatus[i2])+=balls2 - balls1;
    std::get<2>(teamStatus[i1])+=balls1;
    std::get<2>(teamStatus[i2])+=balls2;
  }

  std::sort(teamStatus.begin(), teamStatus.end(), std::greater<std::tuple<int, int, int, int>>());

  std::vector<std::string> passedTeams;
  for (int i = 0; i < n/ 2; i++) {
    passedTeams.push_back(teamNames[std::get<3>(teamStatus[i])]);
  }

  std::sort(passedTeams.begin(), passedTeams.end());
  for (size_t i = 0; i < passedTeams.size(); i++) {
    out << passedTeams[i] << std::endl;
  }
}


int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}