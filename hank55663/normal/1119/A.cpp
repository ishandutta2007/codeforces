#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n;
	vector<int> v[300005];
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		v[x].pb(i);
	}
	int ans=0;
	for(int i =1;i<=n;i++){
		if(v[i].empty())continue;
		int now=n-1;
		for(int j=v[i].size()-1;j>=0;j--){
			if(now!=v[i][j]){
				ans=max(ans,now-v[i][0]);
				break;
			}
			now--;
		}
		now =  0;
		for(int j =0;j<v[i].size();j++){
			if(now!=v[i][j]){
				ans=max(v[i].back()-now,ans);
				break;
			}
			now++;
		}
	}
	printf("%d\n",ans);
}
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc