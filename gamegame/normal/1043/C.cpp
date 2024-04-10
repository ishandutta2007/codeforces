#include<iostream>
#include<algorithm>
using namespace std;
int n;
string s[1001],b[1001];
string t;
bool srev[1001],brev[1001];
int ans[1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	n=t.size();
	t='?'+t;
	for(int i=1; i<=n ;i++){
		string rs=s[i-1],rb=b[i-1];
		reverse(rs.begin(),rs.end());
		reverse(rb.begin(),rb.end());
		if(s[i-1]+t[i]<t[i]+rb){
			srev[i]=false;
			s[i]=s[i-1]+t[i];
		}
		else{
			srev[i]=true;
			s[i]=t[i]+rb;
		}
		if(b[i-1]+t[i]>t[i]+rs){
			brev[i]=false;
			b[i]=b[i-1]+t[i];
		}
		else{
			brev[i]=true;
			b[i]=t[i]+rs;
		}
	}
	bool is=true;
	for(int i=n; i>=1 ;i--){
		if(is){
			ans[i]=srev[i];
			if(srev[i]) is=!is;
		}
		else{
			ans[i]=brev[i];
			if(brev[i]) is=!is;
		}
	}
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
	cout << endl;
}