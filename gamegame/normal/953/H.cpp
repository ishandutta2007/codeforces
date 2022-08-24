#include<iostream>
#include<queue>
using namespace std;
int n,k;
vector<int>r,o,w;
int d[200001];
int solve(vector<int>a,vector<int>b){
	if(a.empty() || a.size()+b.size()<k) return 0;
	int maxa=0,maxb=0;
	int posa,posb;
	for(int i=0; i<a.size() ;i++){
		if(a[i]>maxa){
			maxa=a[i];
			posa=i;
		}
	}
	for(int i=0; i<b.size() ;i++){
		if(b[i]>maxb){
			maxb=b[i];
			posb=i;
		}
	}
	int ans=maxa+maxb;
	priority_queue<int>pq;
	for(int i=0; i<a.size() ;i++) if(i!=posa) pq.push(a[i]);
	for(int i=0; i<b.size() ;i++) if(i!=posb) pq.push(b[i]);
	for(int i=0; i<k-2; i++){
		ans+=pq.top();
		pq.pop();
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> d[i];
	}
	char c;
	for(int i=1; i<=n ;i++){
		cin >> c;
		if(c=='R') r.push_back(d[i]);
		else if(c=='O') o.push_back(d[i]);
		else w.push_back(d[i]);
	}
	if(k==1 || o.empty()){
		cout << "-1\n";
		return 0;
	}
	int ans=max(solve(r,o),solve(w,o));
	if(ans==0) cout << "-1\n";
	else cout << ans << endl;
}