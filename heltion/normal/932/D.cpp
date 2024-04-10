#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto no = [](){cout << "No";exit(0);};
#define maxn 400000
LL w[maxn], sw[maxn];
int f[20][maxn], D[maxn];
int main(){
	ios::sync_with_stdio(false);
	int Q, cnt = 1;
	LL last = 0;
	cin >> Q;
	D[1] = 1;
	while(Q --){
		LL t, p, q;
		cin >> t >> p >> q;
		if(t == 1){
			LL R = p ^ last, W = q ^ last;
			while(R && w[R] < W) R = f[0][R];
			cnt += 1;
			f[0][cnt] = R;
			D[cnt] = D[R] + 1;
			w[cnt] = W;
			sw[cnt] = sw[R] + W;
			for(int i = 1; i < 20; i += 1)f[i][cnt] = f[i - 1][f[i - 1][cnt]]; 
		}
		else{
			LL R = p ^ last, X = q ^ last;
			int ans = 0;
			for(int i = 19; i >= 0; i -= 1)
				if(sw[R] - sw[f[i][R]] <= X){
					X -= sw[R] - sw[f[i][R]];
					ans += D[R] - D[f[i][R]];
					R = f[i][R];
				}
			cout << ans << endl;
			last = ans;
		}
	}
}