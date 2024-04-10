// Codeforce Beta Round #7
// Problem B -- Memory Manager
#include <iostream>
#include <string>

using namespace std;

int t, m, b[101];

int main()
{
    for(int i = 1; i <= 100; ++ i)
        b[i] = 0;
    int c = 0;
    for(cin >> t >> m; t > 0; -- t)
    {
        string com;
        cin >> com;
        if(com == "alloc")
        {
            int n, s = 0;
            cin >> n;
            for(int i = 1; i <= m; ++ i)
            {
                s = b[i]? 0: s + 1;
                if(s == n)
                {
                    cout << ++ c << "\n";
                    for(int j = i - n + 1; j <= i; ++ j)
                        b[j] = c;
                    break;
                }
            }
            if(s < n)
                cout << "NULL\n";
        }
        else
        if(com == "erase")
        {
            int x, s = 0;
            cin >> x;
            for(int i = 1; i <= m; ++ i)
                if(b[i] == x)
                    b[i] = 0, s ++;
            if(x == 0 || s == 0)
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
        }
        else
        {
            int i = 1;
            for(int j = 1; j <= m; ++ j)
                if(b[j])
                {
                    int temp = b[j];
                    b[j] = 0, b[i ++] = temp;
                }
        }
    }
    return 0;
}