#include<iostream>
#include<algorithm>
using namespace std;
int cnt[58];
bool cmp(char i,char j){
	return i>j;
}
int main(){
	string u,v;
	cin >> u >> v;
	int n=u.size();
	for(int i=0; i<n ;i++) cnt[u[i]]++;
	if(u.size()<v.size()){
		for(char c=57; c>=48 ;c--)
			for(int i=0; i<cnt[c] ;i++) cout << c;
		cout << endl;
		return 0;
	}
	sort(u.begin(),u.end());
	for(int i=0; i<n ;i++){
		string t=u;
		auto pos=lower_bound(t.begin(),t.end(),v[0]);
		int num;
		if(pos==t.end()){
			for(int i=u.size()-1; i>=0; i--){
				cout << u[i];
			}
			return 0;
		}
		else num=*pos;
		t.erase(pos);
		int cv=v[0];
		v.erase(v.begin());
		if(t<=v && num==cv){
			u.erase(lower_bound(u.begin(),u.end(),cv));
			cout << (char)num;
			continue;
		}
		pos=lower_bound(u.begin(),u.end(),cv);
		pos--;
		num=*pos;
		cout << (char)num;
		for(auto i=u.end(); i!=u.begin() ;){
			i--;
			if(i!=pos) cout << *i;
		}
		return 0;
	}
}