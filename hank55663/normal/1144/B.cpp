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
	scanf("%d",&n);
	vector<int> v[2];
	int sum=0;
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		v[x&1].pb(x);
		sum+=x;
	}
	for(int i =0;i<2;i++){
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
	}
	for(int i =0;i<v[0].size()||i<v[1].size();i++){
		if(i<v[0].size()&&i<v[1].size()){
			sum-=v[0][i];
			sum-=v[1][i];
		}
		else if(i<v[0].size()){
			sum-=v[0][i];
			break;
		}
		else{
			sum-=v[1][i];
			break;
		}
	}
	printf("%d\n",sum);
}