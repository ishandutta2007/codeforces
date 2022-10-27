#include <bits/stdc++.h>
using namespace std;

int query(int a, int b, int c){
	cout << "? " << a << " " << b << " " << c << endl;
	int x; cin >> x; return x^1;
}

const int maxN = 10005;

int A[maxN], verdict[maxN];

void solve(){
	int n;
	cin >> n;
	for(int i = 0; 3*i < n; i++){
		verdict[i] = query(3*i + 1, 3*i + 2, 3*i + 3);
	}
	int pos0 = -1, pos1 = -1;
	for(int i = 1; 3*i < n; i++){
		if(verdict[i - 1] == 0 && verdict[i] == 1){
			vector<int> x(6);
			iota(x.begin(), x.end(), 3*(i - 1) + 1);
			if(query(x[1], x[2], x[3])){
				A[x[0]] = 0;
				A[x[3]] = 1;
				pos0 = x[0]; pos1 = x[3];
				for(int p : {1, 2, 4, 5}){
					A[x[p]] = query(pos0, pos1, x[p]);
				}
				
			}else if(query(x[2], x[3], x[4])){
				A[x[1]] = 0;
				A[x[4]] = 1;
				pos0 = x[1]; pos1 = x[4];
				for(int p : {0, 2, 3, 5}){
					A[x[p]] = query(pos0, pos1, x[p]);
				}
			}else{
				A[x[2]] = 0;
				A[x[5]] = 1;
				pos0 = x[2]; pos1 = x[5];
				for(int p : {0, 1, 3, 4}){
					A[x[p]] = query(pos0, pos1, x[p]);
				}
			}
			break;
		}
		if(verdict[i - 1] == 1 && verdict[i] == 0){
			vector<int> x(6);
			iota(x.begin(), x.end(), 3*(i - 1) + 1);
			if(!query(x[1], x[2], x[3])){
				A[x[0]] = 1;
				A[x[3]] = 0;
				pos1 = x[0]; pos0 = x[3];
				for(int p : {1, 2, 4, 5}){
					A[x[p]] = query(pos0, pos1, x[p]);
				}
				
			}else if(!query(x[2], x[3], x[4])){
				A[x[1]] = 1;
				A[x[4]] = 0;
				pos1 = x[1]; pos0 = x[4];
				for(int p : {0, 2, 3, 5}){
					A[x[p]] = query(pos0, pos1, x[p]);
				}
			}else{
				A[x[2]] = 1;
				A[x[5]] = 0;
				pos1 = x[2]; pos0 = x[5];
				for(int p : {0, 1, 3, 4}){
					A[x[p]] = query(pos0, pos1, x[p]);
				}
			}
			break;
		}
	}
	assert(pos0 != -1);
	for(int i = 0; 3*i < n; i++){
		if(i == (pos0 - 1)/3)continue;
		if(i == (pos1 - 1)/3)continue;
		int x1 = 3*i + 1;
		int x2 = 3*i + 2;
		int x3 = 3*i + 3;
		if(verdict[i]){
			if(query(pos0, x1, x2)){
				A[x1] = 1;
				A[x2] = 1;
				A[x3] = query(pos1, pos0, x3);
			}else{
				A[x3] = 1;
				A[x1] = query(pos1, pos0, x1);
				A[x2] = 1 - A[x1];
			}
		}else{
			if(!query(pos1, x1, x2)){
				A[x1] = 0;
				A[x2] = 0;
				A[x3] = query(pos1, pos0, x3);
			}else{
				A[x3] = 0;
				A[x1] = query(pos1, pos0, x1);
				A[x2] = 1 - A[x1];
			}
		}
	}
	vector<int> imposters;
	for(int i = 1; i <= n; i++){
		if(A[i])imposters.emplace_back(i);
	}
	cout << "! " << (int)imposters.size() << " ";
	for(int i = 0; i < (int)imposters.size(); i++){
		cout << imposters[i] << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}