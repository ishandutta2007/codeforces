#include <bits\stdc++.h>
main()
{
    int n; std::string s;  std::cin >> n >> s;
    std::cout << ((n > 26) ? -1 : n - (int)std::set<char>(s.begin(), s.end()).size());
}