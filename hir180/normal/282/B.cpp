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
	string ans="";
	int n;
	int now=0;
	scanf("%d",&n);
	int a1=0,g1=0;
	for(int i=0;i<n;i++){
		int a,g;
		scanf("%d %d",&a,&g);
		if(a1+a-g1>=-500 && a1+a-g1<=500){
			ans.pb('A');
			a1+=a;
		}else{
			ans.pb('G');
			g1+=g;
		}
	}
	cout << ans << endl;
}