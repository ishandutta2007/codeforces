#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int n,m,res=4;
    bool metOnSide = false;
    int q = 0;
    cin>>n>>m;
    int table[n][m];
    for (int i = 0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>table[i][j];
            if (table[i][j] == 1) {
                //good
                if ((i == 0 || i == n-1 || j == 0 || j == m-1)&& !metOnSide) {
                    //on side
                    metOnSide=true;
                    res-=2;
                }
            }
        }
    }
    cout<<res;

    return 0;
}