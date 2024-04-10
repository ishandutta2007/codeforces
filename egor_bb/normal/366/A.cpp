#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <array>
#include <cmath>
using namespace std;


int main (){
  int n;
  cin >> n;
  int t = 100000000, it;
  int t1, t2, t3, t4, it1, it2;
  for (int i=0; i<4; i++){
	  cin >> t1 >> t2 >> t3 >> t4;
	  if (min(t1, t2) + min (t3, t4) < t){
		  t=min(t1, t2) + min (t3, t4);
		  it=i;
		  it1 = min (t1, t2);
		  it2 = min (t3, t4);
	  }
  }
  if (t<=n){
	  cout << it+1 << " " << it1 << " " << n-it1;  
  } else cout << -1;
  return(0);



}