#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
vector<int>v;
ll x,y;
void ask(){
	cout << "?";
	for(auto cur:v) cout << ' ' << cur;
	cout << endl;
	cin >> x >> y;
	v.clear();
}
ll gdx,gdy;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	if(k==1){
		cout << "! " << k << endl;
		return 0;
	}
	for(int i=1; i<=k ;i++) v.push_back(i);
	ask();
	gdx=x;gdy=y;
	int bad=1+(gdx==1);
	int cnt=0;
	int eq1=0,eq2=0;
	int b1=0,s1=0;
	int b2=0,s2=0;
	int fx;
	for(int i=k+1; i<=n ;i++){
		for(int j=1; j<=k ;j++){
			if(j!=bad) v.push_back(j);
		}
		v.push_back(i);
		ask();
		if(y==gdy) eq1++;
		else if(y<gdy) b1++;
		else s1++;
		if(i==k+1) fx=(eq1!=0)+(b1!=0)*2;
	}
	for(int i=1; i<=k ;i++){
		if(i==gdx || i==bad) continue;
		for(int j=1; j<=k ;j++){
			if(j!=i) v.push_back(j);
		}
		v.push_back(k+1);
		ask();
		if(y==gdy) eq2++;
		else if(y<gdy) s2++;
		else b2++;
	}
	int t1=0,t2=0;
	if(fx==0) t2=1;
	else if(fx==2) t1=1;
	else if(b1!=0 || b2!=0) t1=t2=1;
	else if(s1!=0 || s2!=0);
	else{
		//min or max
		for(int i=1; i<=k+1 ;i++) if(i!=gdx) v.push_back(i);
		ask();
		if(y>gdy) cout << "! " << 1 << endl;
		else cout << "! " << k << endl;
		return 0;
	}
	//cout << t1 << ' ' << t2 << endl;
	//cout << b2 << ' ' << s2 << ' ' << eq2 << endl;
	int ff[2];
	ff[0]=ff[1]=0;
	ff[t1]++;
	ff[0]+=b2;
	ff[1]+=s2;
	ff[t2]+=eq2;
	cout << "! " << ff[0]+1 << endl;
}