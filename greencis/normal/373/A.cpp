#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
using namespace std;

int n;
char p[9][9];
int freq[10];

int main()
{
    cin >> n;
    for (int i =0;i<4;++i) {
        cin>>p[i];
        for (int j = 0; j < 4; ++j) {
            if (p[i][j]!='.')
                ++freq[p[i][j]-'0'];
        }
    }

    n*=2;
    for (int i = 0;i<10;++i){
        if (freq[i]>n) {
            cout<<"NO";
            return 0;
        }
    }

    cout << "YES";


    return 0;
}