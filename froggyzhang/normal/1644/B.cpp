#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd(time(0));
set<vector<int> > S;
int n;
bool check(const vector<int> &A){
	for(int i=2;i<(int)A.size();++i){
		if(A[i]==A[i-1]+A[i-2])return false;
	}
	return true;
}
void Solve(){
	cin>>n;
	int jb=n;
	vector<int> p(n);
	for(int i=0;i<n;++i)p[i]=i+1;
	S.clear();
	while(jb){
		shuffle(p.begin(),p.end(),rnd);
		if(!S.count(p)&&check(p)){
			S.insert(p);
			for(auto x:p)cout<<x<<' ';
			cout<<'\n';
			--jb;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}