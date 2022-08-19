#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> st;

const int MAXN = 100010;

int N;
int A[MAXN];

int main() {
	cin >> N;
	for(int i = N - 1; i >= 0; i--) cin >> A[i];
	for(int i = 0; i < N; i++) {
		int a = A[i];
		st.push_back(a);
		while(st.size() >= 2 && st[st.size() - 1] == st[st.size() - 2]) {
			st.pop_back();
			st[st.size() - 1] ++;
		}
		//cerr << st.size() << '\n';
	}
	//for(int i = 0; i < st.size(); i++) cerr << st[i] << ' '; cerr << '\n';
	cout << 1 + st[0] - st.size() << '\n';
	return 0;
}