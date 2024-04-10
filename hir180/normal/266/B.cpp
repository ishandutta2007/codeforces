#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	string str;
	cin >> str;
	for(int q=0;q<m;q++){
	vector<int>vec;
	vec.resize(0);
	for(int i=0;i<n-1;i++){
		if(str[i]=='B' && str[i+1]=='G'){
			vec.pb(i);
		}
	}
	for(int j=0;j<vec.size();j++){
		swap(str[vec[j]],str[vec[j]+1]);
	}
	}
	cout << str << endl;
}