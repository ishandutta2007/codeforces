#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    int n;
    cin >> n;
    vector <int> v(n,0);
    for(int i=0;i<n;i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++)
        if (v[i]!=v[i-1])
        {
            cout << v[i] << endl;
            return 0;
        }
    cout << "NO\n";
    return 0;
}