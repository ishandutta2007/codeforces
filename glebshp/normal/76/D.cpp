
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;
typedef unsigned long long LL;

int main()
{
    LL a,b;
    cin>>a>>b;
    if (a%2!=b%2||a<b){
        cout<<"-1\n";
    } else {
        LL x=(a-b)/2;
        LL y=(a+b)/2;
        cout<<x<<"\n"<<y<<"\n";
    }
    return 0;
}