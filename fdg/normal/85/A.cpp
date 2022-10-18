#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stack>

using namespace std;


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    char F[5][102]={0};
    int n;
    cin >> n;
    if (n==1)
    {
        cout << "a\na\nb\nb\n";
        return 0;
    }
    if (n==2)
    {
        cout << "aa\nbb\ncc\ndd\n";
        return 0;
    }
    if (n&1)
    {
        for(int i=0;i+1<n;i+=2)
        {
            if ((i/2)%2==0)
            {
                F[0][i]=F[0][i+1]='a';
                F[1][i]=F[1][i+1]='b';
            }
            else
            {
                F[0][i]=F[0][i+1]='c';
                F[1][i]=F[1][i+1]='d';
            }
        }
        F[0][n-1]=F[1][n-1]='e';
        for(int i=1;i+1<n;i+=2)
        {
            if ((i/2)%2==0)
            {
                F[2][i]=F[2][i+1]='x';
                F[3][i]=F[3][i+1]='w';
            }
            else
            {
                F[2][i]=F[2][i+1]='y';
                F[3][i]=F[3][i+1]='z';
            }
        }
        F[2][0]=F[3][0]='f';
    }
    else
    {
        for(int i=0;i+1<n;i+=2)
        {
            if ((i/2)%2==0)
            {
                F[0][i]=F[0][i+1]='a';
                F[3][i]=F[3][i+1]='a';
            }
            else
            {
                F[0][i]=F[0][i+1]='b';
                F[3][i]=F[3][i+1]='b';
            }
        }
        F[1][n-1]=F[2][n-1]='f';
        for(int i=1;i+1<n;i+=2)
        {
            if ((i/2)%2==0)
            {
                F[1][i]=F[1][i+1]='x';
                F[2][i]=F[2][i+1]='w';
            }
            else
            {
                F[1][i]=F[1][i+1]='y';
                F[2][i]=F[2][i+1]='z';
            }
        }
        F[1][0]=F[2][0]='e';
    }
    cout << F[0] << endl << F[1] << endl << F[2] << endl << F[3] << endl;
    return 0;
}