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
	string a,b;
	cin >> a >> b;
	int A=0,B=0;
	for(int i=0;i<a.size();i++){
		A+=a[i]-'0';
	}
	for(int i=0;i<b.size();i++){
		B+=b[i]-'0';
	}
	A+=(A%2);
	if(A<B){
		puts("NO");
	}else{
		puts("YES");
	}
}