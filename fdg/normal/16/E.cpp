#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <memory.h>

#define dat cin
#define sol cout

using namespace std;

double D[20][20]={0};
int n=0;

double F[1<<18]={0};

int main()
{
//  ifstream dat("input.txt");
//  ofstream sol("output.txt");
    dat >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dat >> D[i][j];
    F[0]=1;
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        {
            if (mask&(1<<i)) continue;
            for(int j=0;j<n;j++)
            {
                if (i==j) continue;
                if (mask&(1<<j)) continue;
                F[mask|(1<<j)]+=F[mask]*D[i][j];
                F[mask|(1<<i)]+=F[mask]*D[j][i];
            }
        }
    }
    sol.precision(10);
    double sum=0;
    for(int i=0;i<n;i++)
        sum+=F[(1<<(n))-1-(1<<i)];
    for(int i=0;i<n;i++)
        if (i==0) sol << F[(1<<(n))-1-(1<<i)]/sum;
        else sol << " " << F[(1<<(n))-1-(1<<i)]/sum;
    sol << endl;
    return 0;
}