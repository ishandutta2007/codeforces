#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll x[2001],y[2001];
bool die[2001];
bool rightturn(int a,int b,int c){
	ll ux=x[b]-x[a],uy=y[b]-y[a];
	ll vx=x[c]-x[b],vy=y[c]-y[b];
	return ux*vy-vx*uy>=0;
}
string s;
int main(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> y[i];
	}
	cin >> s;
	int st=1;
	for(int i=1; i<=n ;i++){
		if(x[st]>x[i]) st=i;
	}
	die[st]=true;
	cout << st << ' ';
	for(int i=1; i<=n-1 ;i++){
		int nw=0;
		for(int j=1; j<=n ;j++){
			if(die[j]) continue;
			if(nw==0) nw=j;
			else if(rightturn(st,nw,j)^(s[i-1]=='L')) nw=j;
		}
		die[nw]=true;
		st=nw;
		cout << st << ' ';
	}
}