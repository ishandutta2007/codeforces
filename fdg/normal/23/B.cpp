#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    int T,N;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> N;
        cout << max(N-2,0) << endl;
    }
    return 0;
}