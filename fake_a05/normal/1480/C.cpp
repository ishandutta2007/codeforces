#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb push_back
#define all(x) begin(x), end(x)

#define rand rng
#define sp ' '
//#define endl '\n'


//#define int long long
const int maxN = 5e5 + 5;

int N, arr[maxN]; 

int q(int p)
{
	if(arr[p]) return arr[p];
	cout << "? " << p << endl;
	cin >> arr[p];
	return arr[p];
}
void a(int p)
{
	cout << "! " << p << endl;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int N; 
	cin >> N; 
	int low = 1, high = N; 
	while(low < high)
	{
		int M = (low + high) / 2;
		q(M);
		q(M + 1);
		if(arr[M] > arr[M + 1]) low = M + 1;
		else high = M;
	}
	a(low);
}