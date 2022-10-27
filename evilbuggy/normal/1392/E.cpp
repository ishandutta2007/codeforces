#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 55;
ll a[N][N], mn[N][N], mx[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j += 2){
			a[i][j] = 1LL << (i + j - 2);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}
	cout<<endl;
	int q; ll k;
	cin>>q;
	while(q--){
		cin>>k;
		int x = 1, y = 1;
		while(x != n || y != n){
			cout<<x<<" "<<y<<'\n';
			k ^= a[x][y];
			if(x == n){
				y++;
			}else if(y == n){
				x++;
			}else	if(a[x + 1][y]){
				if(k&a[x + 1][y])x++;
				else y++;
			}else{
				if(k&a[x][y + 1])y++;
				else x++;
			}
		}
		cout<<n<<" "<<n<<endl<<endl;
	}

	return 0;
}