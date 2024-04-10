#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <ctime>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,cur=1;
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        cur=(cur+i);
        if (cur>n) cur-=n;
        if (i==1) cout << cur;
        else cout << " " << cur;
    }
    cout << endl;
    return 0;
}