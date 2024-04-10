#include<bits/stdc++.h>
using namespace std;
set<int> si;
set<int, greater<int> > sd;
void no(){
	printf("NO");
	exit(0);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		if(not si.count(a)) si.insert(a);
		else if(not sd.count(a)) sd.insert(a);
		else no();
	}
	puts("YES");
	printf("%d\n", (int)si.size());
	for(int x : si) printf("%d ", x);
	printf("\n%d\n", (int)sd.size());
	for(int x : sd) printf("%d ", x);
}