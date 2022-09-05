#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define ll long long
#define pb push_back
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)

int t[105];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	RE(_,n) {
		int a;
		cin >> a;
		RI(i,a)t[i]++;
	}
	RI(i,n) {
		int s = 0;
		RI(j,100) if(t[j]>n-i) s++;
		cout << s << " ";
	}
	return 0;
}