#include <bits/stdc++.h>

std::string solve(std::size_t n, std::string const& s, std::string const& t) {
  auto sf = s[0];
  auto sl = s[1];
  auto tf = t[0];
  auto tl = t[1];
  if (sf == tf && sl != sf && tl != sf && sl != tl) {
    std::string answer{};
    for (auto ch = 'a'; ch <= 'c'; ++ch) {
      if (ch == sf) {
        continue;
      }
      answer += std::string(n, ch);
    }
    answer += std::string(n, sf);
    return answer;
  }
  if (sl == tl && sf != sl && tf != sl && sf != tf) {
    std::string answer(n, sl);
    for (auto ch = 'a'; ch <= 'c'; ++ch) {
      if (ch == sl) {
        continue;
      }
      answer += std::string(n, ch);
    }
    return answer;
  }
  if (sf != sl && tf != tl && sf == tl && sl == tf) {
    std::string answer(n, sf);
    for (char ch = 'a'; ch <= 'c'; ++ch) {
      if (ch == sf || ch == sl) {
        continue;
      }
      answer += std::string(n, ch);
      break;
    }
    answer += std::string(n, sl);
    return answer;
  }
  std::string result = "abc";
  do {
    bool fail = false;
    for (std::size_t i = 0; i != result.size(); ++i) {
      auto test = std::string{result[i], result[(i + 1) % result.size()]};
      if (test == s || test == t) {
        fail = true;
        break;
      }
    }
    if (fail) {
      continue;
    }
    std::string answer{};
    while (n--) {
      answer += result;
    }
    return answer;
  } while (std::next_permutation(result.begin(), result.end()));
  std::cerr << s << ' ' << t << "\n";
  std::cerr << "fuck\n";
  throw;
}

int main() {
  std::size_t n;
  std::cin >> n;
  std::string s, t;
  std::cin >> s >> t;
  std::cout << "YES\n" << solve(n, s, t) << '\n';
  // for (std::size_t n = 1; n <= 3; ++n) {
  //   for (auto sf = 'a'; sf <= 'c'; ++sf) {
  //     for (auto sl = 'a'; sl <= 'c'; ++sl) {
  //       for (auto tf = 'a'; tf <= 'c'; ++tf) {
  //         for (auto tl = 'a'; tl <= 'c'; ++tl) {
  //           auto s = std::string{sf, sl};
  //           auto t = std::string{tf, tl};
  //           auto res = solve(n, s, t);
  //           for (auto ch = 'a'; ch <= 'c'; ++ch) {
  //             if (std::count(res.begin(), res.end(), ch) != n) {
  //               std::cerr << "fail count\n";
  //               std::cerr << n << ' ' << s << ' ' << t << '\n';
  //               std::cerr << res << '\n';
  //               exit(0);
  //             }
  //           }
  //           for (std::size_t i = 0; i != res.size() - 1; ++i) {
  //             auto test = std::string{res[i], res[i + 1]};
  //             if (test == s || test == t) {
  //               std::cerr << "fail occ\n";
  //               std::cerr << n << ' ' << s << ' ' << t << '\n';
  //               std::cerr << res << '\n';
  //               exit(0);
  //             }
  //           }
  //         }
  //       }
  //     }
  //   }
  // }
  return 0;
}