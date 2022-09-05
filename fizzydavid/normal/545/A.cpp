#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstdlib>
//#include <ctime>
#include <iomanip>
#include <cstring>
#include <climits>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int n,cnt;
vector<int> v;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			if(x==1 || x==3)flag=false;
		}
		if(flag){
			v.push_back(i);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		cout<<v[i]<<' ';
	}
}