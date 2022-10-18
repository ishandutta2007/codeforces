#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int val[256];
    val['6']=6; val['7']=7; val['8']=8; val['9']=9;
    val['T']=10; val['J']=11; val['Q']=12; val['K']=13; val['A']=14;
    char cc,f1,s1,f2,s2;
    cin >> cc >> f1 >> s1 >> f2 >> s2;
    if (s1==s2&&val[f1]>val[f2]||s1==cc&&s2!=cc) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}