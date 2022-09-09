#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
char s[maxn];
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
		int n;
		cin >> n >> (s + 1);
		int k = n;
		for(int i = 1; i <= n; i += 1) a[i] = 0;
		for(int i = 1; i < n; i += 1) if(s[i] == '>')
			a[i] = k --;
		int L = 1;
		for(int i = 1; i <= n; i += 1){
			if(a[i]) L = i + 1;
			else{
				if(i == n or a[i + 1]){
					for(int j = i; j >= L; j -= 1) a[j] = k --;
					L = i + 1;
				}
			}
		}
		for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
		cout << "\n";
		for(int i = 1; i <= n; i += 1) a[i] = 0;
		k = n;
		for(int i = 1; i < n; i += 1) if(s[i] == '>')
			a[i] = k --;
		k = 1;
		for(int i = 1; i <= n; i += 1) if(not a[i])
			a[i] = k ++;
		for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
		cout << "\n";
    }
    return 0;
}