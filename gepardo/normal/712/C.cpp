#include <iostream>

main()
{
    int x, y; std::cin >> y >> x;
    int ans = 2;
    y -= x;
    int f1 = 0, f2 = x-1;
    while (y > 0)
    {
        y -= f2;
        int f = f1 + f2;
        f1 = f2; f2 = f;
        ans++;
    }
    std::cout << ans << std::endl;
}