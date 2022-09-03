#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	int n;
	set<int> s;
	scanf("%d ",&n);
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		s.insert(x);
	}
	if(s.size()>3){
		printf("-1\n");
		return 0;
	}
	vector<int> v;
	for(auto it:s)
	v.pb(it);
	if(v.size()==3){
		if(v[2]-v[1]==v[1]-v[0]){
			printf("%d\n",v[2]-v[1]);
		}
		else{
			printf("-1\n");
		}
	}
	if(v.size()==2){
		if((v[1]-v[0])%2){
			printf("%d\n",v[1]-v[0]);
		}
		else{
			printf("%d\n",(v[1]-v[0])/2);
		}
	}
	if(v.size()==1){
		printf("0\n");
	}
}