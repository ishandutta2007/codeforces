#include <iostream>

using namespace std;

#define keysX {3, 0, 0, 0, 1, 1, 1, 2, 2, 2}
#define keysY {1, 0, 1, 2, 0, 1, 2, 0, 1, 2}

const int keyX[] = keysX, keyY[] = keysY;

int n;
string s;
int vx[100], vy[100];

bool can(int x, int y)
{
    for (int i = 0; i < 10; i++)
        if (keyX[i] == x && keyY[i] == y) return true;
    return false;
}

int main()
{
    cin >> n >> s;
    for (int i = 1; i < n; i++)
        vx[i] = keyX[s[i] - '0'] - keyX[s[i-1] - '0'],
        vy[i] = keyY[s[i] - '0'] - keyY[s[i-1] - '0'];
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        int x = keyX[i], y = keyY[i];
        cnt++;
        for (int j = 1; j < n; j++)
        {
            x += vx[j], y += vy[j];
            if (!can(x, y))
            {
                cnt--;
                break;
            }
        }
    }
    cout << ((cnt == 1) ? "YES" : "NO") << endl;
}