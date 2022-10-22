#include <bits/stdc++.h>

using namespace std;

bool rightAngle(vector<vector<int> > x){
	int n0=0;
	for(int i=0; i < 3; ++i){
		int j=i, k=(i+1)%3, l=(i+2)%3;
		int dot=(x[j][0]-x[k][0])*(x[l][0]-x[k][0]);
		dot+=(x[j][1]-x[k][1])*(x[l][1]-x[k][1]);
		if(dot == 0)
			n0++;
	}
	return n0==1;
}

int main(){
	vector<vector<int> > x;
	for(int i=0; i < 3; ++i){
		x.push_back(vector<int>());
		for(int j=0; j < 2; ++j){
			int a;
			cin >> a;
			x[i].push_back(a);
		}
	}
	if(rightAngle(x)){
		puts("RIGHT");
		return 0;
	}
	else{
		for(int i=0; i < 3; ++i)
			for(int j=0; j < 2; ++j)
				for(int k=-1; k <= 1; k += 2){
					x[i][j] += k;
					if(rightAngle(x)){
						puts("ALMOST");
						return 0;
					}
					x[i][j] -= k;
				}
	}
	puts("NEITHER");
}