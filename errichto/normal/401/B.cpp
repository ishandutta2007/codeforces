#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

bool t[4005];

int main()
{
	ios_base::sync_with_stdio(0);

	int now, k;
	cin >> now >> k;

	while(k--){
		int kind;
		cin >> kind;
		int a;
		cin >> a;
		t[a] = 1;
		if (kind == 1){
			cin >> a;
			t[a] = 1;
		}
	}
	int mi, ma;
	mi = ma = 0;
	RI(i,now-1){
		if(!t[i]) ma++;
	}
	RI(i,now-1){
		if(!t[i]){
			mi++;
			if(!t[i+1]) i++;
		}
	}
	cout << mi << " " << ma;


	return 0;
}