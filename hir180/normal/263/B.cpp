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
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	vector<int>vec;
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int rp;
		scanf("%d",&rp);
		vec.pb(rp);
	}
	sort(vec.begin(),vec.end());
	if(k>vec.size()){
		puts("-1");
	}else{
		printf("%d %d\n",vec[vec.size()-k],vec[vec.size()-k]);
	}
}