#include <bits/stdc++.h>

using namespace std;

map<int, int> Nx;
map<int, int> Pr;
set<int> in;
set<int> out;

int main(){
	int n;
	scanf("%d", &n);
	int F=0;
	for(int i=0; i < n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		Nx[a]=b;
		Pr[b]=a;
		in.insert(b);
		out.insert(a);
	}
	int cur1;
	for(auto it=out.begin(); it != out.end(); ++it){
		if(in.find(*it) == in.end())
			cur1=*it;
	}
	int cur2=Nx[0];
	while(cur1 || cur2){
		if(cur1)printf("%d ", cur1);
		if(cur2)printf("%d ", cur2);
		if(cur1)cur1=Nx[cur1];
		if(cur2)cur2=Nx[cur2];
	}
}