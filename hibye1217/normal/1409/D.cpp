#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf push_front
#define mt make_tuple
#define endl '\n'
#define up front()
#define tp top()
#define em empty()
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
#define dec(x) cout.setf(ios::fixed); cout.precision(x);
#define t1(x) cout << #x << ' ' << x << endl ;
#define t2(x,y) cout << #x << ' ' << x << " / " << #y << ' ' << y << endl ;
#define t3(x,y,z) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << endl ;
#define t4(x,y,z,w) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << " / " << #w << ' ' << w << endl ;
#define t5(x,y,z,w,v) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << " / " << #w << ' ' << w << " / " << #v << ' ' << v << endl ;
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
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
	Fast;
	int t = 1;
	cin >> t;
	while (t--){
		string n;
		int s;
		cin >> n >> s;
		int nl = n.size();
		int arr[20] = {}, ans[20] = {}, sum[20] = {};
        for (int i = 1; i <= nl; i++) arr[i] = n[i-1]-'0';
		for (int i = 0; i <= nl; i++) ans[i] = arr[i];
		for (int i = 1; i <= nl; i++){
			sum[i] = sum[i-1] + ans[i];
			if (sum[i] > s){
				for (int j = i; j > 0; j--){
                    if (s - sum[j-1] < ans[j]){
						ans[j] = 0;
						ans[j-1] += 1;
						sum[j-1] += 1;
                    }
                    else{
						break;
                    }
				}
				for (int j = i+1; j <= nl; j++) ans[j] = 0;
				sum[0] = ans[0];
				for (int j = 1; j <= i; j++) sum[j] = sum[j-1] + ans[j];
				break;
			}
		}
		ull a=0, b=0;
        for (int i = 0; i <= nl; i++){
			a *= 10;
			a += arr[i];
        }
        for (int i = 0; i <= nl; i++){
			b *= 10;
			b += ans[i];
        }
        cout << b-a << endl;
	}
}