#include<iostream>
using namespace std;
int main(){
	int a,ta,b,tb,c,d;
	char u;
	cin >> a >> ta >> b >> tb >> c >> u >> d;
	c=c*60+d-300;
	d=c+ta;
	int ans=0;
	for(int i=0; i<1140 ;i+=b){
		int s=i,e=i+tb;
		if(e<=c || s>=d){
			continue;
		}
		ans++;
	}
	cout << ans << endl;
}