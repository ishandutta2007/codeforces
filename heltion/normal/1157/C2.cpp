// Author: Heltion
// Date: 2019-04-26
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	int L = 1, R = n, Last = 0;
	string s, sl, sr;
	while(L <= R){
		if(a[L] < a[R]){
			if(Last < a[L]){
				s.push_back('L');
				Last = a[L];
				L += 1;
				continue;
			}
			else if(Last < a[R]){
				s.push_back('R');
				Last = a[R];
				R -= 1;
				continue;
			}
			else break;
		}
		else if(a[L] > a[R]){
			if(Last < a[R]){
				s.push_back('R');
				Last = a[R];
				R -= 1;
				continue;
			}
			else if(Last < a[L]){
				s.push_back('L');
				Last = a[L];
				L += 1;
				continue;
			}
			else break;
		}
		else{
			int l = L, r = R, last = Last;
			while(l <= r){
				if(a[l] > last){
					sl.push_back('L');
					last = a[l];
					l += 1;
				}
				else break;
			}
			l = L, r = R, last = Last;
			while(l <= r){
				if(a[r] > last){
					sr.push_back('R');
					last = a[r];
					r -= 1;
				}
				else break;
			}
			break;
		}
	}
	if(sl.size() > sr.size()) cout << (s.size() + sl.size()) << endl << (s + sl);
	else cout << (s.size() + sr.size()) << endl << (s + sr);
	return 0;
}