#include <iostream>
#include <string>

using namespace std;

int main()
{
    string max;
    int m = -123123123;
    string a;
    int n;
    cin >> n;
    while (n--)
    {
        int b,c,d,e,f,g,h;
        cin >> a >> b>>c>>d>>e>>f>>g>>h;
        int t = b*100-c*50+d+e+f+g+h;
        if (t > m)
        {
            m = t;
            max = a;
        }
    }
    cout << max << endl;
    return 0;
}