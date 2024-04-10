#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto no = [](){cout<<"No";exit(0);};
auto read = [](){LL x;cin>>x;return x;}; 
#define maxn 1200000
LL c[maxn], t[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> c[i];
	for(int i = 1; i <= n; i += 1) cin >> t[i];
	if(c[1] != t[1] || c[n] != t[n]) no();
	for(int i = n; i >= 1; i -= 1) c[i] -= c[i - 1], t[i] -= t[i - 1];
	sort(c + 1, c + n + 1);
	sort(t + 1, t + n + 1);
	//for(int i = 1; i <= n; i += 1) cout << c[i] << endl;
	//for(int i = 1; i <= n; i += 1) cout << t[i] << endl;
	for(int i = 1; i <= n; i += 1) if(c[i] != t[i]) no();
	cout << "Yes";
}