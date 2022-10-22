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

vector<pair<int, int> > v1;
vector<pair<int, int> > v2;
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int y=a;
	for(int x=1; x < a; ++x){
		while(y*y+x*x > a*a)
			--y;
		if(y*y+x*x == a*a)
			v1.push_back(make_pair(x, y));
	}
	y=b;
	for(int x=1; x < b; ++x){
		while(y*y+x*x > b*b)
			--y;
		if(y*y+x*x == b*b)
			v2.push_back(make_pair(x, y));
	}
	for(int i=0;  i< v1.size(); ++i)
		for(int j=0; j < v2.size(); ++j){
			pair<int, int> p1=v1[i], p2=v2[j];
			if(p1.first*p2.second == p1.second*p2.first){
				if(p1.second == p2.first)
					continue;
				puts("YES");
				printf("0 0\n");
				printf("%d %d\n", p1.first, p1.second);
				printf("%d %d\n", -p2.second, p2.first);
				return 0;
			}
		}
	puts("NO");
	return 0;
}