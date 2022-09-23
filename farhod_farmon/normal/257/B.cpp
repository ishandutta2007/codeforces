#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdlib>

#define pb push_back

using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<max( a, b )-1<<" "<<a+b-( max( a, b )-1 )-1;
    //system( "pause" );
    return 0;    
}