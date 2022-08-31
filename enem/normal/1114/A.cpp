#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int x,y,z,a,b,c;
    cin>>x>>y>>z>>a>>b>>c;
    if(a>=x&&(b+a-x>=y)&&(a+b+c-x-y>=z)) cout<<"YES";
    else cout<<"NO";
    return 0;
}