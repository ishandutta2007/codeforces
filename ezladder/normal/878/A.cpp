#include <bits/stdc++.h>
          
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double	
//ANKETA

int n;
int was0[10];
int was1[10];
int ans[3];

int main(){ 
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < 10; i++) was0[i] = 0, was1[i] = 1;
    for (int i = 0; i < n; i++){
    	char c;
    	int x;
    	cin >> c >> x;
    	for (int j = 0; j < 10; j++){
	    	int b = (x >> j) & 1;
	    	if (c == '|'){
	    		was0[j] |= b;
	    		was1[j] |= b;
	    	} else if (c == '&'){
	    		was0[j] &= b;
	    		was1[j] &= b;
	    	} else {
	    		was0[j] ^= b;
	    		was1[j] ^= b;
	    	}
    	}
    }

    ans[1] = 1023;

    for (int j = 0; j < 10; j++){
    	if (was0[j] == 0 && was1[j] == 0){
    		ans[1] ^= (1 << j);
    	}
    	if (was0[j] == 0 && was1[j] == 1){
    	}
    	if (was0[j] == 1 && was1[j] == 0){
    		ans[2] ^= (1 << j);
    	}
    	if (was0[j] == 1 && was1[j] == 1){;
    		ans[0] ^= (1 << j);
    	}
    }
    cout << 3 << "\n";
    cout << "|" << ' ' << ans[0] << "\n";
    cout << "&" << ' ' << ans[1] << "\n";
    cout << "^" << ' ' << ans[2] << "\n";
}