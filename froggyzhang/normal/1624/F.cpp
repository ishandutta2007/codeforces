#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define zz has_no_jb
int X;
int n;
inline int Ask(int x){
	cout<<"+ "<<x<<endl;
	#ifdef zz
	X+=x;
	return X/n;
	#endif
	cin>>x;
	return x;
}
void Report(int x){
	cout<<"! "<<x<<endl;
	#ifdef zz
	cerr<<" ans: "<<X<<endl;
	#endif
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	#ifdef zz
	cin>>X;
	#endif
	int t=0;
	int o=1;
	while((o<<1)<n)o<<=1;
	int las=0;
	while(o>=1){
		int nt=Ask(o+las);
		if(nt^t)las=n-o;
		else las=0;
		t=nt;
		o>>=1;
	}
	if(las)Report(n*t);
	else Report(n*(t+1)-1);
	return 0;
}