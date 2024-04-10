#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
bool cz[10];
ll cnt[10];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n ;i++){
		string s;
		int cur=1;
		cin >> s;
		for(int j=s.size()-1; j>=0 ;j--){
			cnt[s[j]-'a']+=cur;
			cur*=10;
		}
		cz[s[0]-'a']=true;
	}
	pair<int,int>a[10];
	for(int i=0; i<10 ;i++){
		a[i]=make_pair(cnt[i],i);
	}
	sort(a,a+10);
	ll ans=0;
	bool z=false;
	int cur=1;
	for(int i=9; i>=0 ;i--){
		if(!cz[a[i].second] && !z){
			z=true;
		}
		else{
			ans+=1LL*cur*a[i].first;
			cur++;
		}
	}
	cout << ans << endl;
}