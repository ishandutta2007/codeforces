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
	int n,h;
	scanf("%d %d",&n,&h);
	int a[1005];
	vector<int> v;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		v.pb(a[i]);
		sort(v.begin(),v.end());
		LL sum=0;
		int st=1;
		if(v.size()&1)st=0;
		for(int j=st;j<v.size();j+=2){
			sum+=v[j];
		}
		if(sum>h){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("%d\n",n);
}
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc