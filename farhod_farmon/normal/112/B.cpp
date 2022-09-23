#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>

#define pb push_back
#define fi first
#define se second

using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if( b==a/2 && c==a/2 || b==a/2+1 && c==a/2 || b==a/2 && c==a/2+1 || b==a/2+1 && c==a/2+1 )cout<<"NO";
    else cout<<"YES";
    return 0;    
}