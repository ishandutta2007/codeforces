#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
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
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.pb(x);
	}
	reverse(v.begin(),v.end());
	vector<int> ans;
	set<int> s;
	for(auto it:v){
		if(s.find(it)==s.end()){
			ans.pb(it);
			s.insert(it);
		}
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto it:ans)
	printf("%d ",it);
}