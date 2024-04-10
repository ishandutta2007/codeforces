#include<iostream>
using namespace std;
int n;
struct rect{
	int x1,x2,y1,y2;
};
rect intersect(rect u,rect v){
	u.x1=max(u.x1,v.x1);
	u.x2=min(u.x2,v.x2);
	u.y1=max(u.y1,v.y1);
	u.y2=min(u.y2,v.y2);
	return u;
}
bool check(rect u){
	return (u.x1<=u.x2 && u.y1<=u.y2);
}
rect a[200001];
rect p[200001],s[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
	}
	p[1]=a[1];
	s[n]=a[n];
	for(int i=2; i<=n ;i++){
		p[i]=intersect(p[i-1],a[i]);
	}
	for(int i=n-1; i>=1 ;i--){
		s[i]=intersect(s[i+1],a[i]);
	}
	for(int i=2; i<n ;i++){
		rect cur=intersect(p[i-1],s[i+1]);
		if(check(cur)){
			cout << cur.x1 << ' ' << cur.y1 << endl;
			return 0;
		}
	}
	rect cur=s[2];
	if(check(cur)){
			cout << cur.x1 << ' ' << cur.y1 << endl;
			return 0;
		}
		cur=p[n-1];
	if(check(cur)){
			cout << cur.x1 << ' ' << cur.y1 << endl;
			return 0;
		}
}