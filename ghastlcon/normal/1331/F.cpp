#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#define N 118
using namespace std;

string f[N] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
bool g[N];

int main(void)
{
    int n;
    string a;
    int i, j;

    for(i = 0; i < N; i ++)
        for(j = 0; j < f[i].size(); j ++)
            f[i][j] = toupper(f[i][j]);
    
    cin >> a;
    n = a.size();
    a = " " + a;
    g[0] = true;
    for(i = 1; i <= n; i ++)
        for(j = 0; j < i; j ++)
            if(find(f, f + N, a.substr(j + 1, i - j)) != f + N)
                g[i] |= g[j];
    cout << (g[n] ? "YES" : "NO") << endl;

    return 0;
}