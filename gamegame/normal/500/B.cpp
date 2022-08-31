#include<bits/stdc++.h>
using namespace std;
int p[100001];
int a[100001];
int n;
vector<int>bin[100001];
vector<int>q;
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
void join(int x,int y){
	p[find(x)]=find(y);
}
int main(){
	int n,t;cin >> n;
	for(int i=1; i<=n ;i++) p[i]=i;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			char c;cin >> c;
			if(c=='1') join(i,j);
		}
	}
	for(int i=1; i<=n ;i++){
		bin[find(i)].push_back(i);
	}
	for(int i=1; i<=n ;i++){
		q.clear();
		for(auto c:bin[i]) q.push_back(a[c]);
		sort(q.begin(),q.end());
		int ptr=0;
		for(auto c:bin[i]){
			a[c]=q[ptr++];
		} 
	}
	for(int i=1; i<=n ;i++) cout << a[i] << ' ';
	cout << endl;
}