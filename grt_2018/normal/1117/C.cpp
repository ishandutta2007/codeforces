#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second

const int MAXN = 1000*100+1;
const long long INF = (long long)1000*1000*1000*1000*1000*1000;

int n;
pair<int,int>s,m;
pair<int,int>T[MAXN];
pair<int,int>V;

bool checkw(long long a) {
	pair<long long,long long>p = s;
	p.ST+=(long long)V.ST*(a/n);
	p.ND+=(long long)V.ND*(a/n);
	p.ST+=T[a - (long long)(a/n)*n].ST;
	p.ND+=T[a - (long long)(a/n)*n].ND;
	long long suma = abs((long long)m.ST - p.ST) + abs((long long)m.ND-p.ND);
	if(suma<=a) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s.ST>>s.ND>>m.ST>>m.ND>>n;
	for(int i=1; i<=n;i++) {
		char a; cin>>a;
		T[i] = T[i-1];
		if(a=='U') T[i].ND++;
		if(a=='D') T[i].ND--;
		if(a=='L') T[i].ST--;
		if(a=='R') T[i].ST++;
	}
	V = T[n];
	long long pocz=0,kon=INF,sr;
	long long ans=-1;
	while(pocz<=kon) {
		sr=(pocz+kon)/2;
		if(checkw(sr)){ kon=sr-1;ans=sr;}
		else pocz=sr+1;
	}
	cout<<ans;
	return 0;
}