/*input

4
1 1
1 2
2 1
2 2

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	set<int> bendr;
  	set<int> a;
 	set<int> b;
  	int n,m;
  cin >> n >> m;
  for(int i = 0;i<n;i++){
    int x;
    cin >> x;
    a.insert(x);
  }
  for(int i = 0;i<m;i++){
    int x;
    cin >> x;
    b.insert(x);
    if(a.count(x))
      bendr.insert(x);
  }

  if(bendr.size()>0){
    cout << *bendr.begin();
    return 0;
  }
  n=*a.begin();
  m=*b.begin();
  cout << min(n,m) << max(n,m);

	return 0;
}