#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl '\n'
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

vector<int> mp[5];

int main(){
	Fast;
	int n, m;
	cin >> n >> m;
	if (min(n, m) >= 4){
		cout << -1;
		return 0;
	}
	if (min(n, m) == 1){
		cout << 0;
		return 0;
	}
	string s;
	for (int i = 0; i < n; i++){
		string x;
		cin >> x;
		s += x;
	}
	if (n > m) n ^= m ^= n ^= m;
	for (int i = 0; i < n; i++){
		mp[i].resize(m);
		for (int j = i*m; j < (i+1)*m; j++){
			mp[i][j-i*m] = s[j]-'0';
		}
	}
	if (n == 2){
		int ans1=0, ans2=0;
		for (int i = 0; i < m; i++){
			int val1 = mp[0][i] + mp[1][i];
			if (i%2 == 0){
				if (val1%2 == 0) ans2++;
				else ans1++;
			}
			else{
				if (val1%2 == 0) ans1++;
				else ans2++;
			}
		}
		cout << min(ans1, ans2);
		return 0;
	}
	if (n == 3){
		int ans1=0, ans2=0, ans3=0, ans4=0;
		for (int i = 0; i < m; i++){
			int val1 = mp[0][i] + mp[1][i] + mp[2][i];
			int val2 = mp[0][i] + mp[1][i];
			int val3 = mp[1][i] + mp[2][i];
			int val4 = mp[2][i];
			int val5 = mp[0][i];
			int val6 = mp[1][i];
			if (i%2 == 0){
				if (val1%3 == 0);
				else ans1++;
				if ((val6==1&&val1==1) || (val1==2&&val6==0));
				else ans3++;
				if ((val3==2&&val5==0) || (val3==0&&val5==1));
				else ans2++;
				if ((val2==2&&val4==0) || (val2==0&&val4==1));
				else ans4++;
			}
			else{
				if (val1%3 == 0);
				else ans3++;
				if ((val6==1&&val1==1) || (val1==2&&val6==0));
				else ans1++;
				if ((val3==2&&val5==0) || (val3==0&&val5==1));
				else ans4++;
				if ((val2==2&&val4==0) || (val2==0&&val4==1));
				else ans2++;
			}
			//cout <<ans1<<' '<<ans2<<' '<<ans3<<' '<<ans4<<endl;
		}
		cout << min(min(ans1, ans2), min(ans3, ans4));
		return 0;
	}
}