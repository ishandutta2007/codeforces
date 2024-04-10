#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,mas[4]={0};
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        mas[a%3]++;
    }
    cout << min(mas[1],mas[2])+mas[0]/2 << endl;
    return 0;
}