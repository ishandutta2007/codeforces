#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto no = [](){cout << "No";exit(0);}; 
#define maxn
int main(){
	ios::sync_with_stdio(false);
	int N, A, B;
	cin >> N >> A >> B;
	for(int a = 0; a * A <= N; a += 1)
		if((N - a * A) % B == 0){
			int b = (N - a * A) / B;
			for(int i = 1; i <= N; i += 1)
				if(i <= a * A){
					if(i % A) cout << i + 1 << " ";
					else cout << i - A + 1 << " ";
				}
				else{
					if((i - a * A) % B) cout << i + 1 << " ";
					else cout << i - B + 1 << " ";
				}
			return 0;
		}
	cout << -1;
}