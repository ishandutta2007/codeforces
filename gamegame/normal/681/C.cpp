#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int> >pq;
	vector<pair<int,int> >ans;
	string s;
	int p;
	for(int i=1; i<=n ;i++){
		cin >> s;
		if(s[0]=='i'){
			cin >> p;
			pq.push(p);
			ans.push_back(make_pair(0,p));
		}
		else if(s[0]=='r'){
			if(pq.empty()){
				ans.push_back(make_pair(0,1));
			}
			else pq.pop();
			ans.push_back(make_pair(1,0));
		}
		else{
			cin >> p;
			while(!pq.empty() && pq.top()<p){
				pq.pop();
				ans.push_back(make_pair(1,0));
			}
			if(pq.empty() || pq.top()!=p){
				ans.push_back(make_pair(0,p));
				pq.push(p);
			}
			ans.push_back(make_pair(2,p));
		}
	}
	cout << ans.size() << endl;
	for(int i=0; i<ans.size() ;i++){
		if(ans[i].first==0){
			cout << "insert " << ans[i].second << endl;;
		}
		else if(ans[i].first==1){
			cout << "removeMin\n";
		}
		else{
			cout << "getMin " << ans[i].second << endl;
		}
	}
}