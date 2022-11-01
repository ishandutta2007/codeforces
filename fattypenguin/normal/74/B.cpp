#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,m,k;
    string s,mode;
    cin >> n >> m >> k >> mode;
    int ss = m;
    m = k;
    k = ss;
    cin >> mode >> s;
    if ("head" == mode)
    {
        m = n-m+1;
        k = n-k+1;
    }
    int l = s.size();
    int t = 0;
    int mt = 0;
    if (m > k)
    {
        mt = (n-m+1)+n-2;
    }
    else
    {
        mt = n-m;
    }
    bool ans = false;
    bool right = true;
    for (int i = 0;i < l-1;++i)
    {
        if ('1' == s[i] || t+1 >= mt)
        {
            if (m == n)
                right = false;
            if (m == 1)
                 right = 1;
            if (right)
            {
                m = m+1;
            }
            else
                --m;
            if (t+1 >= mt && '1' != s[i])
            {
                ans = true;
                t = i-t+mt;
                break;
            }
            else
            {
                t = 0;
                if (((m == 1 && !right) || (m == n && right)))
                {
                    mt = n-1;
                }
                else
                {
                    if (right)
                        mt = (n-m+1)+n-2;
                    else
                        mt = n+m-2;
                }
            }
        }
        else
        {
            ++t;
            if (m == n)
                right = false;
            if (m == 1)
                 right = 1;
            if (right)
            {
                m = m+1;
            }
            else
                --m;;
        }
    }
    if (ans)
        cout << "Controller " << t << endl;
    else
        cout << "Stowaway" << endl;
    return 0;
}