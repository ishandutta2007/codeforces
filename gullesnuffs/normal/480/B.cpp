#include <bits/stdc++.h>

using namespace std;

int n, l, x[2];
set<int> A;

int main(){
	scanf("%d%d%d%d", &n, &l, x, x+1);
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		A.insert(a);
	}
	bool done[2]={0,0};
	bool both=0;
	int bothI;
	for(auto it = A.begin(); it != A.end(); ++it){
		for(int i=0; i < 2; ++i){
			if(A.find(*it+x[i]) != A.end())
				done[i]=1;
		}
		if(A.find(*it+x[0]+x[1]) != A.end()){
			bothI=*it+x[0];
			both=1;
		}
		if(A.find(*it+x[1]-x[0]) != A.end() && *it+x[1] < l){
			bothI=*it+x[1];
			both=1;
		}
		if(A.find(*it+x[1]-x[0]) != A.end() && *it-x[0] > 0){
			bothI=*it-x[0];
			both=1;
		}
	}
	if(!done[0] && !done[1]){
		if(both){
			puts("1");
			printf("%d\n", bothI);
		}
		else{
			printf("2\n%d %d\n", x[0], x[1]);
		}
	}
	else if(!done[1])
		printf("1\n%d\n", x[1]);
	else if(!done[0])
		printf("1\n%d\n", x[0]);
	else
		printf("0\n");
}