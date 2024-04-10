#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n;
string s;
bool hv[27];
int cnt[27];
bool check(int mid){
	for(int i=1; i<=26 ;i++) cnt[i]=hv[i]=0;
	for(int i=1; i<=mid ;i++){
		cnt[s[i]-96]++;
	}
	for(int i=1; i<=26 ;i++) if(cnt[i]!=0) hv[i]=true;
	for(int i=mid+1; i<=n ;i++){
		cnt[s[i]-96]++;
		cnt[s[i-mid]-96]--;
		if(cnt[s[i-mid]-96]==0) hv[s[i-mid]-96]=false;
	}
	for(int i=1; i<=26 ;i++){
		if(hv[i]) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	n=s.size();
	s=' '+s;
	int l=1,r=n,mid;
	while(l!=r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout << l << endl;
}