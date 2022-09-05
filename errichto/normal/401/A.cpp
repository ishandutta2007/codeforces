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



int main()
{
	ios_base::sync_with_stdio(0);

	int n,x;
	cin>>n>>x;
	int s = 0;
	while(n--){
		int a;
		cin>>a;
		s+=a;
	}
	if(s<0) s = -s;
	int licz = 0;
	while(s>0){
		s-=x;
		licz++;
	}
	cout<<licz;


	return 0;
}