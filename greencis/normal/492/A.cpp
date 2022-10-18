#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
 int n;
 cin>>n;
 int cur=0,q=1;
 while(1){
  cur += q*(q+1)/2;
  if (cur > n) {cout<<q-1;return 0;}
  ++q;
 }
}