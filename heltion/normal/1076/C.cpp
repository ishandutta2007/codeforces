#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL;
int main(){
	int t;
	cin >> t;
	while(t --){
		int d;
		cin >> d;
		//x - d x + d = 0
		int del = d * d - 4 * d;
		if(del < 0) printf("N\n");
		else{
			printf("Y %.9lf %.9lf\n", (d + sqrt(del)) / 2, (d - sqrt(del)) / 2); 
		}
	}
}