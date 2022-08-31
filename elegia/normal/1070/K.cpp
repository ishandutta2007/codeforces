#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;
	
	int A[100005];
	for(int i = 1; i <= N; i++)
		cin >> A[i];
	
	int sum = accumulate(&A[1], &A[N]+1, 0);
	
	if(sum % K != 0 || sum / K < *max_element(&A[1], &A[N]+1)) {
		cout << "No";
		return 0;
	}
	
	vector<int> ans;	
	for(int i = 1; i <= N; ) {
		int j = i;
		int now = A[i];
		while(now < sum / K) {
			j++;
			now += A[j];
		}
		
		if(now > sum / K) {
			cout << "No";
			return 0;
		}
		
		ans.push_back(j-i+1);
		i = j + 1;
	}
	
	cout << "Yes" << endl;
	for(auto i : ans)
		cout << i << ' ';
}