#include<iostream>
#include<set>
using namespace std;
int a[200001];
int nl[200001];
int nr[200001];
set<pair<int,int> >l;
set<pair<int,int> >r;
set<int>::iterator it;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	l.insert(make_pair(-a[1],1));
	r.insert(make_pair(a[1],1));
	for(int i=2; i<=n ;i++){
		l.insert(make_pair(-a[i],i));
		r.insert(make_pair(a[i],i));
		pair<int,int> num1=*l.upper_bound(make_pair(-a[i],i));
		pair<int,int> num2=*r.upper_bound(make_pair(a[i],i));
		cout << a[max(num1.second,num2.second)] << ' ';
	}
}