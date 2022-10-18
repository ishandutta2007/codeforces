#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
 int a,b,c;
 cin>>a>>b>>c;
 cout<<max(a+b+c,max(a*b*c,max(a+b*c,max(a*b+c,max((a+b)*c,a*(b+c))))));
}