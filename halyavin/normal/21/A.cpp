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

bool isSymbol(char c) {
  if (c >= 'a' && c <= 'z') return true;
  if (c >= 'A' && c <= 'Z') return true;
  if (c >= '0' && c <= '9') return true;
  return c == '_';
}

std::vector<std::string> split(const std::string& host, char c) {
  std::vector<std::string> result;
  size_t pos = 0;
  for (size_t i = 0; i < host.length(); i++) {
    if (host[i] == c) {
      result.push_back(host.substr(pos, i - pos));
      pos = i + 1;
    }
  }
  result.push_back(host.substr(pos));
  return result;
}

bool isHost(const std::string& host) {
  if (host.length() < 1 || host.length() > 32) return false;
  std::vector<std::string> words = split(host, '.');
  for (std::string word : words) {
    if (word.length() < 1 || word.length() > 16) return false;
    for (size_t i = 0; i < word.length(); i++) {
      if (!isSymbol(word[i])) return false;
    }
  }
  return true;
}

bool isResource(const std::string& resource) {
  if (resource.length() < 1 || resource.length() > 16) return false;
  for (size_t i = 0; i < resource.length(); i++) {
    if (!isSymbol(resource[i])) return false;
  }
  return true;
}

bool isGood(const std::string& s) {
  int pos = s.find('@');
  if (pos == s.npos) return false;
  std::string name = s.substr(0, pos);
  if (name.length() < 1 || name.length() > 16) return false;
  for (size_t i = 0; i < name.length(); i++) {
    if (!isSymbol(name[i])) return false;
  }
  std::string rest = s.substr(pos + 1);
  pos = rest.find('/');
  std::string host;
  if (pos == s.npos) {
    return isHost(rest);
  } else {
    return isHost(rest.substr(0, pos)) && isResource(rest.substr(pos + 1));
  }
}

void run(std::istream& in, std::ostream& out) {
  std::string s;
  in >> s;
  if (isGood(s)) {
    out << "YES" << std::endl;
  } else {
    out << "NO" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}