#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int a,b,c,x,y,z;
void wa()
{
    cout<<"NO";
    exit(0);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>x>>y>>z>>a>>b>>c;
    if(a<x) wa();
    a-=x;
    if(a+b<y) wa();
    a-=y;
    if(a+b+c<z) wa();
    cout<<"YES";
    return 0;
}