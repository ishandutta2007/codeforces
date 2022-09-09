#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto no = [](){cout<<"No";exit(0);};
auto read = [](){LL x;cin>>x;return x;}; 
#define maxn 120000
map<LL, LL> ans;
int main(){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q --){
		LL a;
		cin >> a;
		if(ans.count(a) == 0){
			LL b = 1;
			while(b * 2 <= a) b *= 2;
			if(a != b * 2 - 1) ans[a] = b * 2 - 1;
			else{
				LL ok = 0;
				for(LL i = 2; i < a; i += 1)
					if(a % i == 0){
						ans[a] = a / i;
						ok = 1;
						break;
					}
				if(ok == 0) ans[a] = 1;
			}
		}
		cout << ans[a] << endl;
	}
}