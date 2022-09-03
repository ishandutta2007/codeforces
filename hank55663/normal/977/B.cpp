#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long double,null_type,less<long double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ld long double
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
int main(){
	map<string,int> m;
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	for(int i = 0;i<n-1;i++){
		m[s.substr(i,2)]++;
	}
	string ans;
	int Max=0;
	for(auto it:m){
		if(it.y>Max){
			Max=it.y;
			ans=it.x;
		}
	}
	cout<<ans<<endl;
}