#include <bits/stdc++.h>
using namespace std;
const int oo = (1 << 30) - 10;

string generate(int occurrence, int l, int r, int n)
{
    string res = "";
    for (int i = 0; i < occurrence; i++) res += "AC";
    if (!l) res = "B" + res;
    if (l == 2) res = "C" + res;
    
    if (r != 1) 
    {
        int has = 0;
        while (int(res.size()) < n) res += "B", has = 1;
        if (!r && !has) res += "B";
    }
    else
    {
        while (int(res.size()) + 1 < n) res += "B";
        res += "A";
    }
    
    if (int(res.size()) != n) return "";
    return res;
}

int calc(int f1, int l1, int r1, int f2, int l2, int r2, int k)
{
    if (!k) return f2;
    int occurrence = f1 + f2 + (r1 == 1 && l2 == 2);
    if (occurrence > oo) occurrence = oo;
    return calc(f2, l2, r2, occurrence, l1, r2, k - 1);
}

int main()
{
    int k, x, m, n;
    cin >> k >> x >> m >> n;
    
    for (int i = 0; i * 2 <= m; i++)
        for (int li = 0; li < 3; li++)
            for (int ri = 0; ri < 3; ri++)
            {
                string s1 = generate(i, li, ri, m);
                if (s1 == "") continue;
                
                for (int j = 0; j * 2 <= n; j++)
                    for (int lj = 0; lj < 3; lj++)
                        for (int rj = 0; rj < 3; rj++)
                        {
                            string s2 = generate(j, lj, rj, n);
                            if (s2 == "") continue;
                            
                            if (calc(i, li, ri, j, lj, rj, k - 2) == x)
                            {
                                cout << s1 << "\n" << s2 << "\n";
                                return 0;
                            }
                        }
            }
            
    cout << "Happy new year!\n";
}