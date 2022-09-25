#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int a,b,c,d;
int x,y,x0,y0,x1,y1;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>a>>b>>c>>d;
		cin>>x>>y>>x0>>y0>>x1>>y1;
		
		if ((a || b) && x0==x1){
			cout<<"No"<<endl;
			continue;
		}
		if ((c || d) && y0==y1){
			cout<<"No"<<endl;
			continue;
		}
		
		x+=(b-a);
		y+=(d-c);
		
		if (x0<=x && x<=x1 && y0<=y && y<=y1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}