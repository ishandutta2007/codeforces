#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
 cin >> n;
 if (n==1||n==2) cout<<"1\n1";
 else if (n==3) cout<<"2\n1 3";
 else if (n==4) cout << "4\n2 4 1 3";
 else {
  cout << n << endl;
  for (int i=0; i<n; ++i) {
   if (i%2) cout << (n+1)/2+1+i/2 << " ";
   else cout << 1+i/2 << " ";
  }
 }
 return 0;
}