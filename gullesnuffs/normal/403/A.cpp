#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int gcd(int a, int b){
	return b?gcd(b, a%b):a;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, p;
		scanf("%d%d", &n, &p);
		int e=0;
		set<pair<int, int> > edges;
		for(int i=1; i == 1 || i == 2 || gcd(i-1, n) != 1; ++i){
			if(gcd(i, n) > 1)
				continue;
			bool first=1;
			for(int j=0; j != 0 || first; j=(j+i)%n){
				j%=n;
				first=0;
				int a=j, b=(j+i)%n;
				if(a > b)swap(a, b);
				edges.insert(make_pair(a, b));
			}
		}
		for(int a=0; a < n; ++a)
			for(int b=a+1; b < n; ++b){
				if(edges.size() >= 2*n+p)
					break;
				if(edges.find(make_pair(a, b)) == edges.end())
					edges.insert(make_pair(a, b));
			}
		for(auto it=edges.begin(); it != edges.end(); ++it)
			printf("%d %d\n", it->first+1, it->second+1);
	}
	return 0;
}