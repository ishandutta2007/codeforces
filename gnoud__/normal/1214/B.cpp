#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x=a+b-c;
    if(min(x+1,c+1)<min({a,b,c})+1) cout<<min(x+1,c+1);
    else cout<<min({a,b,c})+1;
}