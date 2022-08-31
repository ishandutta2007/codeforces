#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	s=' '+s;
	int ans=0,took=0,r=0;
	for(int l=1; l<=n ;l++){//'a'
		while(r<n && took<k){
			r++;
			if(s[r]=='b'){
				took++;
			}
		}
		while(r<n){
			r++;
			if(s[r]=='b'){
				r--;
				break;
			}
		}
		ans=max(ans,r-l+1);
		if(s[l]=='b') took--;
	}
	took=r=0;
	for(int i=1; i<=n ;i++){
		s[i]=195-s[i];
	}
	for(int l=1; l<=n ;l++){//'b'
		while(r<n && took<k){
			r++;
			if(s[r]=='b'){
				took++;
			}
		}
		while(r<n){
			r++;
			if(s[r]=='b'){
				r--;
				break;
			}
		}
		ans=max(ans,r-l+1);
		if(s[l]=='b') took--;
	}
	cout << ans << endl;
}