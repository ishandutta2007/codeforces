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
using namespace std;
typedef pair<int,int> p;
typedef pair<int,p> P;
typedef pair<p,p> p2;
#define p push
#define pb push_back
#define mp make_pair
int main(){
	string str;
	bool a=true;
	for(int i=0;i<8;i++){
	cin>>str;
	if(str=="BWBWBWBW" || str=="WBWBWBWB"){
	}else{
		a=false;
	}
	}
	if(a){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}