#include<bits/stdc++.h>
using namespace std;
#define maxn 320000
char s[maxn];
int a[maxn];
int main(){
	int n;
	cin >> n >> s;
	for(int i = 0; i < n; i += 1) a[s[i] - '0'] += 1;
	for(int i = n - 1; i >= 0 && a[0] > n / 3; i -= 1) if(s[i] == '0'){
		a[0] -= 1;
		s[i] = 0;
	}
	for(int i = 0; i < n && a[2] > n / 3; i += 1) if(s[i] == '2'){
		a[2] -= 1;
		s[i] = 0;
	}
	for(int i = 0; i < n; i += 1){
		if(s[i] == 0){
			if(a[0] < n / 3){
				a[0] += 1;
				s[i] = '0';
			}
			else if(a[1] < n / 3){
				a[1] += 1;
				s[i] = '1';
			}
			else if(a[2] < n / 3){
				a[2] += 1;
				s[i] = '2';
			}
		}
		else if(s[i] == '1' && a[1] > n / 3 && a[0] < n / 3){
			a[1] -= 1;
			a[0] += 1;
			s[i] = '0';
		}
	}
	for(int i = n - 1; i >= 0 && a[2] < n / 3 && a[1] > n / 3; i -= 1) if(s[i] == '1'){
		a[2] += 1;
		a[1] -= 1;
		s[i] = '2';
	}
	cout << s;
}