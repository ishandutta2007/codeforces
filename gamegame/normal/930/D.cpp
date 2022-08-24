#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int odd,even;
int miny[400001],maxy[400001],min2y[400001],max2y[400001];
vector<int>p[400001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<=2e5 ;i++){
		maxy[i]=-1,miny[i]=2e5+1;
	}
	for(int i=1; i<=n ;i++){
		int u,v,x,y;
		cin >> u >> v;
		x=v-u;
		y=u+v;
		x+=2e5;
		y+=2e5;
		p[x].push_back(y);
	}
	for(int i=0; i<=4e5 ;i++){
		sort(p[i].begin(),p[i].end());
		miny[i]=min2y[i]=4e5+1;
		maxy[i]=max2y[i]=-1;
	}
	for(int i=1; i<=4e5 ;i++){
		if(i>1) maxy[i]=maxy[i-2];
		if(i>1) miny[i]=miny[i-2];
		if(!p[i-1].empty()) maxy[i]=max(maxy[i],p[i-1].back()-1);
		if(!p[i-1].empty()) miny[i]=min(miny[i],p[i-1][0]+1);
	}
	long long ans=0;
	for(int i=4e5-1; i>=0 ;i--){
		if(i<4e5-1) max2y[i]=max2y[i+2];
		if(i<4e5-1) min2y[i]=min2y[i+2];
		if(!p[i+1].empty()) max2y[i]=max(max2y[i],p[i+1].back()-1);
		if(!p[i+1].empty()) min2y[i]=min(min2y[i],p[i+1][0]+1);
		maxy[i]=min(maxy[i],max2y[i]);
		miny[i]=max(miny[i],min2y[i]);
		if(maxy[i]>=miny[i]){
			ans+=(maxy[i]-miny[i])/2+1;
		}
	}
	cout << ans << endl;
}