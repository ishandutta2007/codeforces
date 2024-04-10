#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
 int n1,n2,n3,n4,n5;
 cin>>n1>>n2>>n3>>n4>>n5;
 int sum=(n1+n2+n3+n4+n5)/5;
 if (sum*5==(n1+n2+n3+n4+n5)&&sum) cout << sum;
 else cout <<-1;
 return 0;
}