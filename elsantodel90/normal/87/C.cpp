#include <iostream>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

const int MAX = 100001;

int val[MAX];
int win[MAX];

int main()
{
    forn(n,MAX)
    {
        const int TOP = 10*MAX;
        static bool seen[TOP];
        static int values[TOP];
        int num = 0;
        for (int k =2; n - (k*(k-1))/2 > 0; k++)
        if ((n - (k*(k-1))/2) % k == 0)
        {
            int x  =(n - (k*(k-1))/2) / k;
            int v = 0;
            forn(i,k)
                v ^= val[x+i];
            values[num++] = v;
            seen[v] = true;
            if (v == 0 && win[n] == 0)
                win[n] = k;
        }
        int mex = 0;
        while (seen[mex]) mex++;
        val[n] = mex;
        forn(i, num)
            seen[values[i]] = false;
    }
    int n; cin >> n;
    if (val[n] == 0)
        cout << -1 << endl;
    else
        cout << win[n] << endl;
    return 0;
}