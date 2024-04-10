#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,k;
ll x;
ll a[200001];
multiset<pair<ll,int> >s,t;
void m1(){
	for(int i=1; i<=k ;i++){
		auto it2=s.begin();
		auto it3=t.begin();
		if(*it2<*it3){
			//cout << "yoyooy" << endl;
			int id=it2->se;
			a[id]-=x;
			s.erase(it2);
			s.insert({a[id],id});
		}
		else{
			int id=it3->se;
			a[id]+=x;
			t.erase(it3);
			t.insert({-a[id],id});
		}
	}
}
void m2(){
	while(s.begin()->fi>=0){
		int id=s.begin()->se;
		s.erase(s.begin());
		a[id]-=x;
		s.insert({a[id],id});
		k--;
	}
	int id=s.begin()->se;
	s.erase(s.begin());
	t.insert({-a[id],id});
}
void m3(){
	while(t.begin()->fi>=0){
		int id=t.begin()->se;
		t.erase(t.begin());
		a[id]+=x;
		t.insert({-a[id],id});
		k--;
	}
	int id=t.begin()->se;
	t.erase(t.begin());
	s.insert({a[id],id});
}
void m4(){
	for(int i=1; i<=k ;i++){
		auto it2=s.begin();
		auto it3=t.begin();
		if(*it2<*it3){
			int id=it2->se;
			a[id]+=x;
			s.erase(it2);
			s.insert({a[id],id});
		}
		else{
			int id=it3->se;
			a[id]-=x;
			t.erase(it3);
			t.insert({-a[id],id});
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k >> x;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]>0) s.insert({a[i],i});
		else t.insert({-a[i],i});
	}
	s.insert({1e18,0});
	t.insert({1e18,0});
	if(s.begin()->fi>=k*x && t.begin()->fi>=k*x && t.size()%2==1){
		m1();
	}
	else if(t.size()%2==1){
		//cout << "hihi" << endl;
		if(*s.begin()<*t.begin()) m2();
		else m3();
		m4();
	}
	else m4();
	for(int i=1; i<=n ;i++) cout << a[i] << ' ';
	cout << '\n';
}