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

bool isGood(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int getInt(std::istream& in) {
  std::string line;
  getline(in, line);
  int res = 0;
  for (size_t i = 0; i < line.length(); i++) {
    if (line[i] >= '0' && line[i] <= '9') {
      res = res * 10 + (line[i] - '0');
    }
  }
  return res;
}

std::vector<std::string> getUsernames(std::istream& in) {
  std::vector<std::string> usernames;
  std::string line;
  getline(in, line);
  int pos = -1;
  for (size_t i = 0; i < line.length(); i++) {
    if (line[i] <= ' ') {
      if (pos >= 0) {
        usernames.push_back(line.substr(pos, i - pos));
        pos = -1;
      }
    } else {
      if (pos < 0) {
        pos = i;
      }
    }
  }
  if (pos >= 0) {
    usernames.push_back(line.substr(pos, line.length() - pos));
  }
  return usernames;
}

std::vector<std::string> getMessage(std::istream& in, std::string& line, std::string& userName) {
  getline(in, line);
  size_t pos = line.length() - 1;
  while (pos > 0 && line[pos] <= ' ') pos--;
  size_t start = 0;
  while (line[start] != ':') start++;
  userName = line.substr(0, start);
  line = line.substr(start + 1, pos - start);
  std::vector<std::string> words;
  {
    int pos = -1;
    for (size_t i = 0; i < line.length(); i++) {
      if (!isGood(line[i])) {
        if (pos >= 0) {
          words.push_back(line.substr(pos, i - pos));
          pos = -1;
        }
      } else {
        if (pos < 0) {
          pos = i;
        }
      }
    }
    if (pos >= 0) {
      words.push_back(line.substr(pos, line.length() - pos));
    }
  }
  return words;
}

void run(std::istream& in, std::ostream& out) {
  int t = getInt(in);
  for (int test = 0; test < t; test++) {
    int users = getInt(in);
    std::vector<std::string> userNames = getUsernames(in);
    int messages = getInt(in);
    std::vector<std::vector<bool>> lineFlags(messages, std::vector<bool>(users));
    std::vector<std::string> messageStr(messages);
    std::vector<std::string> messageUserNames(messages);
    for (int i = 0; i < messages; i++) {
      std::vector<std::string> words = getMessage(in, messageStr[i], messageUserNames[i]);
      for (int j = 0; j < users; j++) {
        lineFlags[i][j] = std::find(words.begin(), words.end(), userNames[j]) == words.end() &&
            (messageUserNames[i] == userNames[j] || messageUserNames[i] == "?");
      }
    }
    std::vector<std::vector<std::pair<int, int>>> dyn(messages);
    {
      int count = 0;
      for (int i = 0; i < users && count < 2; i++) {
        if (lineFlags[0][i]) {
          dyn[0].emplace_back(i, -1);
          count++;
        }
      }
    }
    for (int i = 1; i < messages; i++) {
      std::vector<std::pair<int, int>>& prevDyn = dyn[i - 1];
      std::vector<std::pair<int, int>>& curDyn = dyn[i];
      std::vector<bool>& flags = lineFlags[i];
      int count = 0;
      for (int j = 0; j < users && count < 2; j++) {
        if (flags[j]) {
          for (size_t k = 0; k < prevDyn.size(); k++) {
            if (prevDyn[k].first != j) {
              curDyn.emplace_back(j, k);
              count++;
              break;
            }
          }
        }
      }
    }
    if (dyn[messages - 1].size() == 0) {
      out << "Impossible" << std::endl;
    } else {
      std::vector<int> answer(messages);
      int pos = 0;
      for (int i = messages - 1; i >= 0; i--) {
        answer[i] = dyn[i][pos].first;
        pos = dyn[i][pos].second;
      }
      for (int i = 0; i < messages; i++) {
        out << userNames[answer[i]] << ":" << messageStr[i] << std::endl;
      }
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}