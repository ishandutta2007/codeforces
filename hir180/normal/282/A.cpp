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
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++){
		string str;
		cin >> str;
		if(str=="X++" || str=="++X") ans++;
		else ans--;
	}
	cout << ans << endl;
}