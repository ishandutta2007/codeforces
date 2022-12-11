#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
            
using namespace std;
            
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[5005];
int func[5001][5001];

int tmp[5001];

vector<pair<int, int> > save[5005];

int ans[100007];

int main(){	
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++){
    	int len = n - i;
    	for (int j = 0; j < 5001; j++){
    		if (i + j < n) tmp[j] = a[i + j];
    		else tmp[j] = 0;
    	}
    	for (int d = 0; d < 13; d++){
    		for (int mask = 0; mask < len; mask++) if (!((mask >> d) & 1)){
    			tmp[mask ^ (1 << d)] ^= tmp[mask];
    		}
    	}
    	for (int j = 0; j < len; j++){
    		func[i][j] = tmp[j];
    		if (j) func[i][j] = max(func[i][j], func[i][j - 1]);
    	}
    }

	int tt;
	cin >> tt;
	for (int it = 0; it < tt; it++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		save[r].pb(mp(l, it));
	}

	for (int i = 0; i < n; i++){
		sort(all(save[i]));
		reverse(all(save[i]));
		int uk = 0;
		int gg = 0;
		for (int j = i; j >= 0; j--){
			gg = max(gg, func[j][i - j]);
			while (uk < save[i].size() && save[i][uk].x == j){
				ans[save[i][uk].y] = gg;
				uk++;
			}
		}
	}

	for (int i = 0; i < tt; i++) cout << ans[i] << ' ';
}