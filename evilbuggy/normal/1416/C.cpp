#include <bits/stdc++.h>
using namespace std;

long long invs[30][2];

void compute(vector<int> &a, int depth){
	int cnt0 = 0, cnt1 = 0;
	long long invcnt0 = 0, invcnt1 = 0;
	vector<int> left, rite;
	for(auto x : a){
		if((x >> depth) & 1){
			cnt1++;
			invcnt1 += cnt0;
			rite.push_back(x);
		}else{
			cnt0++;
			invcnt0 += cnt1;
			left.push_back(x);
		}
	}
	invs[depth][0] += invcnt0;
	invs[depth][1] += invcnt1;
	if(depth != 0){
		if(!left.empty())compute(left, depth - 1);
		if(!rite.empty())compute(rite, depth - 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(invs, 0, sizeof(invs));
	compute(a, 29);

	long long answer = 0, answerx = 0;
	for(int i = 0; i < 30; i++){
		if(invs[i][0] <= invs[i][1]){
			answer += invs[i][0];
		}else{
			answer += invs[i][1];
			answerx ^= (1 << i);
		}
	}
	cout << answer << " " << answerx << '\n';

	return 0;
}