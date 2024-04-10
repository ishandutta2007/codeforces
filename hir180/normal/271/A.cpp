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
	vector<int>vec;
	for(int i=1000;i<=9999;i++){
		int root[4];
		int r=i;
		for(int j=0;j<4;j++){
			root[j]=r%10;
			r/=10;
		}
		sort(root,root+4);
		if(root[0]!=root[1] && root[1]!=root[2] && root[2]!=root[3]){
			vec.pb(i);
		}
	}
	int ro;
	scanf("%d",&ro);
	printf("%d\n",vec[upper_bound(vec.begin(),vec.end(),ro)-vec.begin()]);
	return 0;
}