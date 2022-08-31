#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
vector<int>cur;
vector<int>newi;
int l[1000002],r[1000002];
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	n=s.size();
	s='!'+s+'!';
	for(int i=1; i<=n ;i++){
		if(s[i]!=s[i-1] && s[i-1]!='!' || s[i]!=s[i+1] && s[i+1]!='!') cur.push_back(i);
		l[i]=i-1;
		r[i]=i+1;
	}
	l[1]=0;
	r[0]=1;
	r[n]=n+1;
	l[n+1]=n;
	int ans=0;
	while(!cur.empty()){
		ans++;
		for(int i=0; i<cur.size() ;i++){
			if(!newi.empty() && newi.back()==cur[i]) newi.pop_back();
			r[l[cur[i]]]=r[cur[i]];
			l[r[cur[i]]]=l[cur[i]];
			if(l[cur[i]]!=0){
				if(s[l[l[cur[i]]]]!=s[l[cur[i]]] && s[l[l[cur[i]]]]!='!' || s[r[l[cur[i]]]]!=s[l[cur[i]]] && s[r[l[cur[i]]]]!='!'){
					if(newi.empty() || newi.back()!=l[cur[i]]) newi.push_back(l[cur[i]]);
				}
				else if(!newi.empty() && newi.back()==l[cur[i]]) newi.pop_back();
			}
			if(r[cur[i]]!=n+1){
				if(s[l[r[cur[i]]]]!=s[r[cur[i]]] && s[l[r[cur[i]]]]!='!' || s[r[r[cur[i]]]]!=s[r[cur[i]]] && s[r[r[cur[i]]]]!='!') newi.push_back(r[cur[i]]);
			}
		}
		cur.clear();
		for(int i=0; i<newi.size() ;i++) cur.push_back(newi[i]);
		newi.clear();
	}
	cout << ans << endl;
}