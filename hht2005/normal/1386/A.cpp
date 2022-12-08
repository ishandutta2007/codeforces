#include <bits/stdc++.h>
using namespace std;
long long jp[70];
bool Query(long long x) {
	cout<<"? "<<x<<endl;
	int t;
	cin>>t;
	return t;
}
int main() {
	int T;
	long long n;
	cin>>T;
	while(T--) {
		cin>>n;
		long long L=1,R=n-1,S=1;
		int cnt=0;
		while(L<=R) {
			S=(L+R)/2;
			jp[++cnt]=S;
			L=S+1;
		}
		S=1;
		for(int i=cnt,f=1;i>=1;i--,f*=-1)S+=f*jp[i];
		L=1,R=n-1;
		int f=cnt&1?-1:1;
		Query(S);
		while(L<=R) {//asdfrgt
			long long mid=(L+R)/2;
			S+=f*mid;
			if(S<1)S+=mid*2;
			if(S>n)S-=mid*2;
			int t;
			if(S<1||S>n)Query(1),t=Query(S=mid+1);
			else t=Query(S);
			if(t)R=mid-1;
			else L=mid+1;
			f*=-1;
		}
		cout<<"= "<<R+1<<endl;
	}
}