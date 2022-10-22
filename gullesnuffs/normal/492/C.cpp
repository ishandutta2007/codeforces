#include <bits/stdc++.h>

using namespace std;

long long n, r, avg;
pair<int, int> exam[100005];


int main(){
	cin >> n >> r >> avg;
	long long tot=n*avg;
	for(int i=0; i < n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		tot -= a;
		exam[i]=make_pair(b, r-a);
	}
	long long ans=0;
	sort(exam, exam+n);
	for(int i=0; (tot > 0); ++i){
		long long num=min((long long)exam[i].second, tot);
		ans += num*exam[i].first;
		tot -= exam[i].second;
	}
	printf("%I64d\n", ans);
}