//Author: Heltion
//Date: 07-31-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 100;
int x[maxn], y[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 0; i <= 4 * n; i += 1) cin >> x[i] >> y[i];
	for(int x1 = 0; x1 <= 50; x1 += 1)
		for(int x2 = x1 + 1; x2 <= 50; x2 += 1)
			for(int y1 = 0; y1 <= 50; y1 += 1)
				for(int y2 = y1 + 1; y2 <= 50; y2 += 1){
					int k = -1;
					for(int i = 0; i <= 4 * n; i += 1){
						if(x[i] < x1 or x[i] > x2 or y[i] < y1 or y[i] > y2
							or(x[i] > x1 and x[i] < x2 and y[i] > y1 and y[i] < y2)){
							if(k == -1) k = i;
							else{
								k = -1;
								break;
							}
						}
					}
					if(~k){
						cout << x[k] << " " << y[k];
						return 0;
					}
				}
	return 0;
}