#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 2) {
        cout << "    0\n";
        cout << "  0 1 0\n";
        cout << "0 1 2 1 0\n";
        cout << "  0 1 0\n";
        cout << "    0";
    } else if (n == 3) {
        cout << "      0\n";
        cout << "    0 1 0\n";
        cout << "  0 1 2 1 0\n";
        cout << "0 1 2 3 2 1 0\n";
        cout << "  0 1 2 1 0\n";
        cout << "    0 1 0\n";
        cout << "      0";
    } else if (n == 4) {
        cout << "        0\n";
        cout << "      0 1 0\n";
        cout << "    0 1 2 1 0\n";
        cout << "  0 1 2 3 2 1 0\n";
        cout << "0 1 2 3 4 3 2 1 0\n";
        cout << "  0 1 2 3 2 1 0\n";
        cout << "    0 1 2 1 0\n";
        cout << "      0 1 0\n";
        cout << "        0";
    } else if (n == 5) {
        cout << "          0\n";
        cout << "        0 1 0\n";
        cout << "      0 1 2 1 0\n";
        cout << "    0 1 2 3 2 1 0\n";
        cout << "  0 1 2 3 4 3 2 1 0\n";
        cout << "0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 3 2 1 0\n";
        cout << "    0 1 2 3 2 1 0\n";
        cout << "      0 1 2 1 0\n";
        cout << "        0 1 0\n";
        cout << "          0";
    } else if (n == 6) {
        cout << "            0\n";
        cout << "          0 1 0\n";
        cout << "        0 1 2 1 0\n";
        cout << "      0 1 2 3 2 1 0\n";
        cout << "    0 1 2 3 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "0 1 2 3 4 5 6 5 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "    0 1 2 3 4 3 2 1 0\n";
        cout << "      0 1 2 3 2 1 0\n";
        cout << "        0 1 2 1 0\n";
        cout << "          0 1 0\n";
        cout << "            0";
    } else if (n == 7) {
        cout << "              0\n";
        cout << "            0 1 0\n";
        cout << "          0 1 2 1 0\n";
        cout << "        0 1 2 3 2 1 0\n";
        cout << "      0 1 2 3 4 3 2 1 0\n";
        cout << "    0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 5 6 5 4 3 2 1 0\n";
        cout << "0 1 2 3 4 5 6 7 6 5 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 5 6 5 4 3 2 1 0\n";
        cout << "    0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "      0 1 2 3 4 3 2 1 0\n";
        cout << "        0 1 2 3 2 1 0\n";
        cout << "          0 1 2 1 0\n";
        cout << "            0 1 0\n";
        cout << "              0";
    } else if (n == 8) {
        cout << "                0\n";
        cout << "              0 1 0\n";
        cout << "            0 1 2 1 0\n";
        cout << "          0 1 2 3 2 1 0\n";
        cout << "        0 1 2 3 4 3 2 1 0\n";
        cout << "      0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "    0 1 2 3 4 5 6 5 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 5 6 7 6 5 4 3 2 1 0\n";
        cout << "0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 5 6 7 6 5 4 3 2 1 0\n";
        cout << "    0 1 2 3 4 5 6 5 4 3 2 1 0\n";
        cout << "      0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "        0 1 2 3 4 3 2 1 0\n";
        cout << "          0 1 2 3 2 1 0\n";
        cout << "            0 1 2 1 0\n";
        cout << "              0 1 0\n";
        cout << "                0";
    } else if (n == 9) {
        cout << "                  0\n";
        cout << "                0 1 0\n";
        cout << "              0 1 2 1 0\n";
        cout << "            0 1 2 3 2 1 0\n";
        cout << "          0 1 2 3 4 3 2 1 0\n";
        cout << "        0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "      0 1 2 3 4 5 6 5 4 3 2 1 0\n";
        cout << "    0 1 2 3 4 5 6 7 6 5 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0\n";
        cout << "0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0\n";
        cout << "  0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0\n";
        cout << "    0 1 2 3 4 5 6 7 6 5 4 3 2 1 0\n";
        cout << "      0 1 2 3 4 5 6 5 4 3 2 1 0\n";
        cout << "        0 1 2 3 4 5 4 3 2 1 0\n";
        cout << "          0 1 2 3 4 3 2 1 0\n";
        cout << "            0 1 2 3 2 1 0\n";
        cout << "              0 1 2 1 0\n";
        cout << "                0 1 0\n";
        cout << "                  0";
    }
    return 0;
}