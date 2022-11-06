#include<bits/stdc++.h>
using namespace std;
template<class T>
void print(vector<T> &a){
	int n=a.size();
	for(int i=0;i<n;++i)
		cout<<a[i]<<" \n"[i+1==n];
}
void work(){
	int n;
	string s,t;
	cin>>n>>s;
	t=s;
	sort(t.begin(),t.end());
	vector<int> a;
	for(int i=0;i<n;++i)
		if(s[i]!=t[i])a.push_back(i+1);
	if(a.size())cout<<"1\n"<<a.size()<<" ",print(a);
	else cout<<"0\n";
}

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--)work();
}