#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	long long x,y;
	while(cin>>x>>y){
		long long n;
		if(x<=y){
			if(y%x==0)n=x;
			else n=y-(x+y)/2%x;
		}
		else{
			n=x+y;
		}
		//cerr<<x<<" "<<y<<" "<<n<<" "<<n%x<<" "<<y%n<<endl;
		assert(n%x==y%n);
		cout<<n<<"\n";
	}
}