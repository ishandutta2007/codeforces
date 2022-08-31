#include<iostream>
#include<algorithm>
#include<queue>
#include<array>
using namespace std;
typedef long long ll;
typedef array<int,10> a10;
string l,r;
ll ans=0;
int f(char c){
	return c-48;
}
ll c[101][101];
void tmw(){
	c[0][0]=1;
	for(int i=1; i<=100 ;i++){
		c[i][0]=1;
		for(int j=1; j<=i ;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
ll g(int mk,int len,a10 rem){
	for(int i=0; i<10 ;i++) len-=rem[i];
	int cnt=0;
	for(int i=0; i<10 ;i++) cnt+=((mk&(1<<i))!=0);
	//cout << mk << ' ' << len << ' ' << cnt << endl;
	if(len<0) return 0;
	if(len==0) return 1;
	if(cnt==0) return 0;
	return c[len+cnt-1][len];
}
struct rem{
	a10 x;
	int y;
};
vector<rem>v;
a10 iu,zero;
int main(){
	ios::sync_with_stdio(false);tmw();
	cin >> l >> r;
	reverse(l.begin(),l.end());reverse(r.begin(),r.end());
	while(l.size()<r.size()) l.push_back(48);
	while(!l.empty() && l.back()==r.back()) l.pop_back(),r.pop_back();
	if(l.empty()){
		cout << "1\n";
		return 0;
	}
	reverse(l.begin(),l.end());reverse(r.begin(),r.end());
	int mk=1023;
	for(int i=f(l[0])+1; i<f(r[0]) ;i++){
		ans+=g(mk,l.size()-1,zero);
		mk^=(1<<i);
	}
	iu[f(l[0])]++;
	v.push_back({zero,mk^(1<<f(l[0]))});
	bool ok=true;
	for(int i=1; i<l.size() ;i++){
		int cur=f(l[i]);
		for(int j=cur+1; j<10 ;j++){
			if((mk&(1<<j))==0) continue;
			ans+=g(mk,l.size()-i-1,zero);
			mk^=(1<<j);
		}
		v.push_back({iu,mk&(1023^(1<<cur))});
		if((mk&(1<<cur))==0){
			ok=false;
			break;
		}
		iu[cur]++;
	}
	if(ok) ans++;
	//cout << "fucked" << endl;
	for(auto tzuyu:v){
		a10 cx=tzuyu.x;
		int mk=tzuyu.y;
		if(cx[f(r[0])]!=0) cx[f(r[0])]--;
		else if(mk&(1<<f(r[0])));
		else continue;
		bool ok=true;
		for(int i=1; i<r.size() ;i++){
			int cur=f(r[i]);
			bool fk=false;
			for(int j=0; j<cur ;j++){
				if(cx[j]!=0){
					cx[j]--;
					ans+=g(mk,r.size()-i-1,cx);
					cx[j]++;
					fk=true;
					break;
				}
				if((mk&(1<<j))==0) continue;
				ans+=g(mk,r.size()-i-1,cx);
				mk^=(1<<j);
			}
			if(fk){
				ok=false;
				break;
			}
			if(cx[cur]!=0) cx[cur]--;
			else if(mk&(1<<cur));
			else{
				ok=false;
				break;
			}
		}
		if(ok) ans++;
	}
	cout << ans << endl;
}